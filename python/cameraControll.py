# Explorer Python (Nathan Butler | iamnbutler@gmail.com)
# Run apt-get install arduino before running this

# Setup
import picamera
import serial
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True
# camera.vflip 			= 	True
locID 							= 	0													# Location ID
dist								=		0													# IR Sensor distance to object

# Read the Arduino info from the Serial port
ser = serial.Serial('/dev/ttyACM0', 9600) 				# Check port with ls /dev/tty*
while 1 :
    ser.readline()</span>

# Take a Picture
def cap():
	camera.capture(uuid.uuid4 + '_loc_' + locID + '.jpg')	# Name image with unique identifier + a location number
	locID = locID + 1
	return

# Take a Video
# def vid():
# 	ccamera.start_recording('video_' + locID + '.h264')
# 	sleep(5)
# 	camera.stop_recording()
# 	locID = locID + 1
# 	return

# Input from arduino
if ( dist > 400 ):
	cap() # Take a photo
	# Do something so that the Explorer doesn't hit the wall
else:
	return