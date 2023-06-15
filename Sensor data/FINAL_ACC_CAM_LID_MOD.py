#camera/lidar
import cv2
import numpy as np
import pyrealsense2 as rs
import time
import matplotlib.pyplot as plt

class Camera():
   
    def __init__(self):
        # Load YOLOv3-tiny weights and configuration files
        self.net = cv2.dnn.readNet('yolov3-tiny.weights', 'yolov3-tiny.cfg')
        # Load coco class labels
        self.classes = []
        with open('coco.names', 'r') as f:
            self.classes = [line.strip() for line in f.readlines()]
        # Initialize RealSense pipeline and start streaming
        self.pipeline = rs.pipeline()
        self.config = rs.config()
        self.config.enable_stream(rs.stream.color,1920,1080, rs.format.bgr8, 30)
        self.config.enable_stream(rs.stream.depth, 1024,768, rs.format.z16, 30)
        self.profile = self.pipeline.start(self.config)
        

        # Create a depth scale for converting depth values to meters
        self.depth_sensor = self.pipeline.get_active_profile().get_device().first_depth_sensor()
        self.depth_scale = self.depth_sensor.get_depth_scale()

        # Set up OpenCL for GPU acceleration
        cv2.ocl.setUseOpenCL(True)
        # Get camera intrinsics
        self.intrinsics = self.profile.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()
        self.Lidistance = 0  # Initial value of lidistance
        self.Cadistance = 0  # Initial value of cadistance
        self.fusion = 0  # Initial value of the fusion
        self.init_dist=0
        self.init_timestamp=0
        self.final_dist = 0
        self.lidistance_history = []
        self.cadistance_history = []
        self.fusion_history = []
        self.ref_speed_history=[]
        self.timestamp_history=[]
# Loop through frames
    def cam_main(self):
        # Wait for a new frame
        frames = self.pipeline.wait_for_frames()
        aligned_frames = rs.align(rs.stream.color)
        aligned_frames.process(frames)
        color_frame = frames.get_color_frame()
        depth_frame = frames.get_depth_frame()
        self.timestamp= depth_frame.get_timestamp()
        

    #lIDAR DISTANCE
        self.Lidistance = depth_frame.get_distance(320,240) 
        #print("Vehicle Distance (lidar):", round(Lidistance, 2), "m")

        if not color_frame or not depth_frame:
            return

        # Convert color image to grayscale
        frame = np.asanyarray(color_frame.get_data())
        depth_image = np.asanyarray(depth_frame.get_data())
        
    # Apply colormap to the depth image
        colormap = cv2.COLORMAP_JET
        colored_image = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), colormap)

# Set a new exposure value
        new_exposure = 10000  # Set the desired exposure value in microseconds
        self.depth_sensor.set_option(rs.option.exposure, new_exposure)


        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # Initialize previous frame if not set
        blur = cv2.GaussianBlur(gray, (21, 21), 0)
        
        # Detect vehicles using YOLOv3-tiny
        blob = cv2.dnn.blobFromImage(frame, 1/255.0, (416, 416), swapRB=True, crop=False)
        self.net.setInput(blob)
        layer_names = self.net.getLayerNames()
        output_layers = [layer_names[i - 1] for i in self.net.getUnconnectedOutLayers()]
        outputs = self.net.forward(output_layers)

        class_ids = []
        confidences = []
        boxes = []
        for output in outputs:
            for detection in output:
                scores = detection[:]
                class_id = np.argmax(scores)
                confidence = scores[class_id]
                if confidence > 0.8 and class_id == 2: # Select only vehicles
                    center_x = int(detection[0] * 640)
                    center_y = int(detection[1] * 480)
                    w = int(detection[2] * 320)
                    h = int(detection[3] * 240)
                    x = int(center_x - w/2)
                    y = int(center_y - h/2)
                    class_ids.append(class_id)
                    confidences.append(float(confidence))
                    boxes.append([x, y, w, h])

        
        # Draw bounding boxes around vehicles and print distances
        indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.8, 0.4,1)
        # Define the font properties
        font = cv2.FONT_HERSHEY_DUPLEX
        fx, fy, cx, cy = self.intrinsics.fx, self.intrinsics.fy, self.intrinsics.ppx, self.intrinsics.ppy
        for i in range(len(boxes)):
            if i in indexes:
                x, y, w, h = boxes[i]
                label = str(self.classes[class_ids[i]])
                # Calculate the current distance
                depth_image = rs.colorizer().colorize(depth_frame)
                image_size= max(w,h)
                image_width = 2.1
                self.Cadistance = ((fx *image_width)/ image_size)
                distance_text = "{:.2f} m".format(self.Cadistance)
                if self.Lidistance == 0 or self.Cadistance == 0:
                    self.fusion = self.Lidistance + self.Cadistance
                    if self.Lidistance == 0 and self.Cadistance== 0:
                     self.final_dist = 0
                
                elif abs(self.Lidistance - self.Cadistance) <= 0.5:
                    self.fusion = (self.Lidistance + self.Cadistance) / 2
                else:
                    self.fusion = self.Cadistance # or any other value indicating an invalid fusion

                # Do something with the updated fusion value
                self.final_dist = round((self.fusion*100),0)
                print("Fusion:", self.final_dist)
                rel_dist= self.final_dist-self.init_dist
                rel_time= self.timestamp-self.init_timestamp
                self.vehicle_speed=10 #assume HAN more vehicle speed
                self.ref_speed= (rel_dist/rel_time)
                self.rel_speed= self.vehicle_speed + self.ref_speed
                print("Ref speed:", round(self.rel_speed,0),"m/s")

                cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0),1)
                cv2.putText(frame, "camera " + str(round(self.Cadistance, 2)) + "m", (x, y + 30), font, 0.5, (255, 0, 255), 2)
                cv2.putText(frame, "lidar" + str(round(self.Lidistance, 2)) + "m", (x, y + 10), font, 0.5, (0, 255, 0), 2)
                #print("Vehicle Distance (camera):", round(Cadistance, 2), "m")
                    # Append the current values to the history lists
                self.lidistance_history.append(self.Lidistance)
                self.cadistance_history.append(self.Cadistance)
                self.fusion_history.append(self.fusion)
                self.ref_speed_history.append(self.ref_speed)
                self.timestamp_history.append(self.timestamp)
                self.init_dist.append(self.init_dist)
               

                 # Plot the historical data

        # Plot the historical data
        plt.plot(self.lidistance_history, label='Lidistance')
        plt.plot(self.cadistance_history, label='Cadistance')
        plt.plot(self.fusion_history, label='Fusion')
        plt.legend()

        # Adjust the plot limits as needed
        plt.ylim(0, 10)

        # Update the plot
        plt.draw()
        plt.pause(0.001)
        plt.clf()


    #Show the color frame with bounding boxes and distances
        cv2.imshow("Color Frame", frame)
        cv2.imshow("Lidar_Frame", colored_image)

        if cv2.waitKey(1) == ord('q'):
            return
        
        return [self.final_dist, self.Lidistance, self.Cadistance]

    def cam_stop(self):
        # Release resources
        self.pipeline.stop()
        cv2.destroyAllWindows()
