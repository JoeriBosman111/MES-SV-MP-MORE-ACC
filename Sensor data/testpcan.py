import PCANBasic
from ctypes import *
import time
import cantools
import FINAL_ACC_CAM_LID
import msvcrt

cam = FINAL_ACC_CAM_LID.Camera()

pcan = PCANBasic.PCANBasic()

pcan.Initialize(Channel=PCANBasic.PCAN_USBBUS1, Btr0Btr1=PCANBasic.PCAN_BAUD_500K)

db = cantools.db.load_file('Radar_DBC.dbc')

pcanmsg = PCANBasic.TPCANMsg()

Speed_setpoint = 5

# Here the seperate messages are pulled from DBC file, only necessary for sending/encoding
RadarConfig = db.get_message_by_name('RadarCfg')
RadarFilt = db.get_message_by_name('FilterCfg_Obj_Size_Dist')
SpeedInfo = db.get_message_by_name('SpeedInformation')
YawInfo = db.get_message_by_name('YawRateInformation')

def C_encode(data):
    my_array = (c_ubyte * len(data))(*data)
    return my_array

def PEAKsend(msg): 
    pcan.Write(Channel=PCANBasic.PCAN_USBBUS1,MessageBuffer=msg)

def PEAKrecv():
    msg_rcv= pcan.Read(Channel=PCANBasic.PCAN_USBBUS1)
    msg_rcv_data=list(msg_rcv[1].DATA)
    msg_rcv_ID = msg_rcv[1].ID
    return [msg_rcv_ID,msg_rcv_data]

def decode_object_data(ID,data):
    if hex(ID)[2:] == '62b':
         # Decoding data based on ID, function will find correct signal from DBC based on ID
        message_dc = db.decode_message(ID,data)
        return {'Object_ID' : message_dc.get('Object_ID'), 
                'Object_DistLong' : message_dc.get('Object_DistLong'),
                'Object_DistLat' : message_dc.get('Object_DistLat'),
                'Object_VrelLong' : message_dc.get('Object_VrelLong'),
                'Object_VrelLat' : message_dc.get('VrelLat'),
                'Object_DynProp' : message_dc.get('DynProp'),
                'Object_RCS' : message_dc.get('Object_RCS')}
    else:
        return print("Incorrect ID")
    
def split_integer(num:int):
    # Extract the lower 8 bits
    lower_byte = num & 0xFF

    # Shift the number 8 bits to the right and extract the resulting lower 8 bits
    upper_byte = (num >> 8) & 0xFF

    return lower_byte, upper_byte   

while True:
    cam_dist = cam.cam_main()
    if cam_dist is not None:
        print(f"Fusion: {cam_dist[0]} | Lidar: {cam_dist[1]} | Camera: {cam_dist[2]}")
    
    cam_dist_1, cam_dist_2 = split_integer(int(cam_dist[0]))
    #print(cam_dist_1,cam_dist_2)

    if msvcrt.kbhit():
        char  = msvcrt.getch()
        print(char.decode())
        if char.decode() == '+':
            Speed_setpoint += 1
    
        elif char == b'-':
            Speed_setpoint -= 1

        if Speed_setpoint > 8:
            Speed_setpoint = 8

        elif Speed_setpoint < 0:
            Speed_setpoint = 0

    print(Speed_setpoint)
    pcanmsg.ID = 0x123
    pcanmsg.DATA = C_encode([cam_dist_1,cam_dist_2,Speed_setpoint,0,70,0,0,0])
    pcanmsg.LEN = len(pcanmsg.DATA)
    PEAKsend(msg=pcanmsg)
    #msg_recv = PEAKrecv()
    #print(f"ID: {hex(msg_recv[0])} | Data: {msg_recv[1]}")
    #if hex(msg_recv[0])[2:] == '62b':
        #print(decode_object_data(msg_recv[0],msg_recv[1]))
    time.sleep(0.01)




#pcan.Uninitialize(Channel=PCANBasic.PCAN_USBBUS1)
