# Explorer Python (Nathan Butler | iamnbutler@gmail.com)
# Run apt-get install arduino before running this

# Setup
import picamera
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True
# camera.vflip 			= 	True

camera.capture(uuid.uuid4() + '_loc_.jpg')	# Name image with unique identifier + a location number

time.sleep(5.0)