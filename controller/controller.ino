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
  // TODO: Get object postion from pi

  if (obj[0] < 34 || obj[0] > 66) { // Check if horizontally centered
    hCenter = FALSE;
  } else {
    hCenter = TRUE;
  }

  if (obj[1] < 34 || obj[1] > 66) { // Check if vertically centered
    vCenter = FALSE;
  } else {
    vCenter = TRUE;
  }

  if (hCenter) {
    // Object is horizontally centered
    return;
  } else {
    // Horizontally center object
    // TODO: Pan to center object


  }

  if (vCenter) {
    // Object is vertically centered
    // TODO: What happens when the object is centered?
    return;
  } else {
    // Center the object
    // TODO: Tilt to center object

  }

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