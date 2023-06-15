#camera/lidar
import cv2
import numpy as np
import pyrealsense2 as rs
import time
import matplotlib.pyplot as plt
# Load YOLOv3-tiny weights and configuration files
net = cv2.dnn.readNet('yolov3-tiny.weights', 'yolov3-tiny.cfg')
# Load coco class labels
classes = []
with open('coco.names', 'r') as f:
    classes = [line.strip() for line in f.readlines()]
# Initialize RealSense pipeline and start streaming
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
profile = pipeline.start(config)

# Create a depth scale for converting depth values to meters
depth_sensor = pipeline.get_active_profile().get_device().first_depth_sensor()
depth_scale = depth_sensor.get_depth_scale()

# Set up OpenCL for GPU acceleration
cv2.ocl.setUseOpenCL(True)
# Get camera intrinsics
intrinsics = profile.get_stream(rs.stream.color).as_video_stream_profile().get_intrinsics()
Lidistance = 0  # Initial value of lidistance
Cadistance = 0  # Initial value of cadistance
fusion = 0  # Initial value of the fusion
init_fusion=0
init_timestamp=0
lidistance_history = []
cadistance_history = []
fusion_history = []
# Loop through frames
while True:
    # Wait for a new frame
    frames = pipeline.wait_for_frames()
    aligned_frames = rs.align(rs.stream.color)
    aligned_frames.process(frames)
    color_frame = frames.get_color_frame()
    depth_frame = frames.get_depth_frame()
    timestamp= depth_frame.get_timestamp()
    

#lIDAR DISTANCE
    Lidistance = depth_frame.get_distance(320,240) 
    #print("Vehicle Distance (lidar):", round(Lidistance, 2), "m")

    if not color_frame or not depth_frame:
        continue

    # Convert color image to grayscale
    frame = np.asanyarray(color_frame.get_data())
    depth_image = np.asanyarray(depth_frame.get_data())
  # Apply colormap to the depth image
    colormap = cv2.COLORMAP_JET
    colored_image = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), colormap)


    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
     # Initialize previous frame if not set
    blur = cv2.GaussianBlur(gray, (21, 21), 0)
    
    # Detect vehicles using YOLOv3-tiny
    blob = cv2.dnn.blobFromImage(frame, 1/255.0, (416, 416), swapRB=True, crop=False)
    net.setInput(blob)
    layer_names = net.getLayerNames()
    output_layers = [layer_names[i - 1] for i in net.getUnconnectedOutLayers()]
    outputs = net.forward(output_layers)

    class_ids = []
    confidences = []
    boxes = []
    distances = []
    vehicle_class_id = 2
    human_class_id = 0
    for output in outputs:
        for detection in output:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]
            if confidence > 0.8 and (class_id == vehicle_class_id or class_id == human_class_id): # Select only vehicles
                center_x = int(detection[0] * 640)
                center_y = int(detection[1] * 480)
                w = int(detection[2] * 640)
                h = int(detection[3] * 480)
                x = int(center_x - w/2)
                y = int(center_y - h/2)
                class_ids.append(class_id)
                confidences.append(float(confidence))
                boxes.append([x, y, w, h])

    # Draw bounding boxes around vehicles and print distances
    indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.8, 0.4,1)
    # Define the font properties
    font = cv2.FONT_HERSHEY_DUPLEX
    font_scale = 0.5
    font_thickness = 2
    fx, fy, cx, cy = intrinsics.fx, intrinsics.fy, intrinsics.ppx, intrinsics.ppy
    for i in range(len(boxes)):
        if i in indexes:
            x, y, w, h = boxes[i]
            label = str(classes[class_ids[i]])
            # Calculate the current distance
            depth_image = rs.colorizer().colorize(depth_frame)
            image_size= max(w,h)
            image_width = 0.5
            Cadistance = ((fx *image_width)/ image_size)
         
            distance_text = "{:.2f} m".format(Cadistance)
            if Lidistance == 0 or Cadistance == 0:
             fusion = Lidistance + Cadistance
            if Lidistance == 0 and Cadistance== 0:
              fusion = 0
            elif abs(Lidistance - Cadistance) <= 0.5:
              fusion = (Lidistance + Cadistance) / 2
            else:
             fusion = Cadistance # or any other value indicating an invalid fusion

             
             while True:
    # Get the latest lidistance and cadistance values from your sensors
              Lidistance = Lidistance # 
              Cadistance = Cadistance # 
            lidistance_history.append(Lidistance)
            cadistance_history.append(Cadistance)
            fusion_history.append(fusion)
    # Do something with the updated fusion value
            print("Fusion:", round(fusion,2),"m")
            rel_dist= fusion-init_fusion
            rel_time= timestamp-init_timestamp
            vehicle_speed=10 #assume vehicle speed
            ref_speed= (rel_dist/rel_time)
            rel_speed= vehicle_speed + ref_speed
            print("Ref speed:", round(rel_speed,2),"m/s")
           

            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0),1)
            cv2.putText(frame, label+"camera " + str(round(Cadistance, 2)) + "m", (x, y + 30), font, 0.5, (255, 0, 255), 2)
            cv2.putText(frame, label+ "lidar" + str(round(Lidistance, 2)) + "m", (x, y + 10), font, 0.5, (0, 255, 0), 2)
            #print("Vehicle Distance (camera):", round(Cadistance, 2), "m")
                # Append the current values to the history lists
                # Open the file in append mode
            log_file = open("fusion_data.log", "a")

# Write fusion data to the file
            def log_fusion_data(distance):
              log_file.write(f"{distance} meters\n")

# Example usage: Log a distance to the file
              fusion = fusion  
              log_fusion_data(fusion)

# Close the file when you're done logging
              log_file.close()

                # Plot the historical data
    plt.plot(lidistance_history, label='Lidistance[m]')
    plt.plot(cadistance_history, label='Cadistance[m]')
    plt.plot(fusion_history, label='Fusion[m]')
    plt.legend()
    plt.xlabel('time[s]')
    plt.ylabel('distance[m]')
    plt.title('Sensor fusion of Camera and LiDAR distances')
    # Adjust the plot limits as needed
    plt.ylim(0, 20)

    # Update the plot
    plt.draw()
    plt.pause(0.1)
    plt.clf()


#Show the color frame with bounding boxes and distances
    cv2.imshow("Color Frame", frame)
    cv2.imshow("Lidar_Frame", colored_image)

    if cv2.waitKey(1) == ord('q'):
        break

# Release resources
pipeline.stop()
cv2.destroyAllWindows()
time.sleep(0.1)