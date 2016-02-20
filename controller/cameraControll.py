# Setup
import picamera
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True
# camera.vflip 			= 	True
locID 							= 	0													# Location ID
dist								=		0													#

# Take a Picture
def cap():
	camera.capture('loc_' + locID + '.jpg')
	locID = locID + 1
	return

# Take a Video
def vid():
	ccamera.start_recording('video_' + locID + '.h264')
	sleep(5)
	camera.stop_recording()
	locID = locID + 1
	return

# Input from arduino
if ( dist > 400 ):
	cap() # Take a photo
	# Do something so that the Explorer doesn't hit the wall
else:
	return