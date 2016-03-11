# ============
# Explorer Bot
# An robot that explores new places and photographs them.
# (Nathan Butler | iamnbutler@gmail.com)
# (Renshen Zhang | )
# (Hyeyoon Kim   | )
# =============

# Run apt-get install arduino before running this

# Setup
import picamera
import uuid
import time
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True											# Uncomment if camera needs to be flipped
# camera.vflip 			= 	True
loops								= 	0													# Var for controlling loops
locID 							= 	0													# Location ID of where photo is taken
capture 						= 	0													# 0 is inactive, 1 is active capture
dist								=		0													# Sensor distance to object

# Read the Arduino info from the Serial port
ser = serial.Serial('/dev/ttyACM0', 9600) 				# Check port with ls /dev/tty*
while 1 :
    ser.readline()</span>

# TODO: Recieve signal from ardino and set capture to 1

def cap():
	# If capture is 1 then take a picture
	if (capture = 1):
		while (loops < 4)
			camera.capture('export/location_' + str(locID) + '_' + str(uuid.uuid1()) + '.jpg')
			loops = loops + 1
			sleep(1.5)				# Wait 1.5s before next photo
		locID = locID +1		# Increment location ID
		loops = 0						# Reset loops
		capture = 0					# Capture is finished

# Input from arduino
if ( dist < 26 ):
	cap() # Take a photo
	# Do something so that the Explorer doesn't hit the wall
else:
	return