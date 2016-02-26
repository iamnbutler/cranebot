# Explorer Python (Nathan Butler | iamnbutler@gmail.com)
# Run apt-get install arduino before running this

# Setup
import picamera
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True
# camera.vflip 			= 	True
int x = 0;

while (x > 20):
  camera.capture(uuid.uuid1() + '_test_' + x + '.jpg')
  x = x + 1
  time.sleep(2)