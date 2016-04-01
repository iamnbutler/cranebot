import serial
arduino = serial.Serial('/dev/cu.usbmodem1421', 9600, timeout=.1)
def read():
	while True:
		data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
		if data:
			dist = int(data)
			if dist > 16:
				print dist
			elif dist < 16:
				print "test"

def cap():
	if capture == TRUE:
		while loops < 4:
			camera.capture('export/location_' + str(locID) + '_' + str(uuid.uuid1()) + '.jpg')
			loops = loops + 1
			sleep(1.5)				# Wait 1.5s before next photo
		locID = locID +1		# Increment location ID
		loops = 0						# Reset loops
		capture = false			# Capture is finished
	else:
		return

read()