# Explorer Python (Nathan Butler | iamnbutler@gmail.com)
# Run apt-get install arduino before running this

# Setup
import picamera
import uuid
import time
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True
# camera.vflip 			= 	True
loops = 0

while (loops > 20):
	camera.capture('export/' + str(uuid.uuid1()) + '_test_' + '.jpg')
	loops = loops + 1
	time.sleep(2)