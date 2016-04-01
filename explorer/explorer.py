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
import serial
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=.1)
camera 							= 	picamera.PiCamera()				# Set up instance of camera
camera.brightness 	= 	60 												# Adjust Brightness
# camera.hflip 			= 	True											# Uncomment if camera needs to be flipped
# camera.vflip 			= 	True
loops								= 	0													# Var for controlling loops
locID 							= 	0													# Location ID of where photo is taken
capture 						= 	0													# 0 is inactive, 1 is active capture
dist								=		0													# Sensor distance to object

# Watch Serial for distance values
def read():
	while True:
		data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
		if data:
			dist = int(data)
			if dist > 16:
				print dist
			elif dist < 16:
				capture = True

# Capture a series of 3 images
def cap():
	if capture:
		while loops < 3:
			camera.capture('export/location_' + str(locID) + '_' + str(uuid.uuid1()) + '.jpg')
			loops = loops + 1
			sleep(1.5)				# Wait 1.5s before next photo
		locID = locID +1		# Increment location ID
		loops = 0						# Reset loops
		capture = false			# Capture is finished
	else:
		return

read()