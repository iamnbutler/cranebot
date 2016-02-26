/* Explorer Controller (Nathan Butler | iamnbutler@gmail.com) */

#include <Servo.h>

Servo panServo;  // create servo object to control a servo
Servo tiltServo;  // create servo object to control a servo

int pan;    // variable to read the value from the analog pin
int tilt;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);

  panServo.attach(9);  // attaches the servo on pin 9 to the servo object
  tiltServo.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.println("Setup Finished");
}

void loop() {
	// Test Pi connection over serial
	Serial.println("Hello, World!");
  delay(1000);
}