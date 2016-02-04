/* Cranebot Controller: Potentiometer Example */

#include <Servo.h>

Servo panServo;  // create servo object to control a servo
Servo tiltServo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int pan;    // variable to read the value from the analog pin
int tilt;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  Serial.println("Setup Start");

  panServo.attach(9);  // attaches the servo on pin 9 to the servo object
  tiltServo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  /* Pan */
  pan = analogRead(potpin);
  pan = map(pan, 0, 1023, 0, 135);
  panServo.write(pan);
  Serial.print("pan: ");
  Serial.println(pan);


  /* Tilt */
  tilt = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  tilt = map(tilt, 0, 1023, 0, 135);     // scale it to use it with the servo (value between 0 and 180)
  tiltServo.write(tilt);
  Serial.print("tilt: ");
  Serial.println(tilt);

  delay(15);                           // waits for the servo to get there
}