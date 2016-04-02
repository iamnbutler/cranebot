#include <Servo.h>

// Definitions
Servo panServo;  // create servo object to control a servo
Servo tiltServo;  // create servo object to control a servo
Servo lWheelServo;  // create servo object to control a servo
Servo rWheelServo;  // create servo object to control a servo


void setup() {
  Serial.begin(9600);

  // Set up servos
  panServo.attach(10);  	// attaches the servo on pin 11 to the servo object
  tiltServo.attach(9);  	// attaches the servo on pin 10 to the servo object
  lWheelServo.attach(8);
  rWheelServo.attach(7);
}

void loop(){
	lWheelServo.write(140);  // set servo to stop
  rWheelServo.write(140);  // set servo to stop
  delay(40);
}
