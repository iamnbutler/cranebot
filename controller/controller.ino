/* Cranebot Controller */

#include <Servo.h>

Servo panServo;  // create servo object to control a servo
Servo tiltServo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int pan;    // variable to read the value from the analog pin
int tilt;    // variable to read the value from the analog pin
int obj[] = { 0, 0 } // xPos, yPos (from 0-100)
bool hCenter = FALSE;
bool vCenter = FALSE;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup Start");

  panServo.attach(9);  // attaches the servo on pin 9 to the servo object
  tiltServo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {

}