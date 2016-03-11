/* Explorer Bot
 * An robot that explores new places and photographs them.
 * (Nathan Butler | iamnbutler@gmail.com)
 * (Renshen Zhang | )
 * (Hyeyoon Kim   | )
 */

// This program uses serial to communicate with Rasberry Pi (explorer.py)
// Do not leave Serial.print() commands in the code outside of debugging

// Includes

#include <Servo.h>

// Definitions
Servo panServo;  // create servo object to control a servo
Servo tiltServo;  // create servo object to control a servo

#define trigPin 13
#define echoPin 12
#define LED_rangeNoInput 11
#define LED_rangeInput 4
#define LED_rangeTrigger 3

const int turnLength = 1000; // Length of the turn in millis

// Variables
int pan = 0;    // variable to read the value from the analog pin
int tilt = 0;   // variable to read the value from the analog pin
int pos = 0;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
long rawDistance, duration, distance;

int movementDirection = 0; // 0 = drive, 1 = reverse, 2 = turn

// Setup
void setup() {
  Serial.begin(9600);

  // Set up servos
  panServo.attach(10);  	// attaches the servo on pin 11 to the servo object
  tiltServo.attach(9);  	// attaches the servo on pin 10 to the servo object

  // Assign Pins
  pinMode(trigPin, OUTPUT); // RF Trig Pin
  pinMode(echoPin, INPUT);	// RF Echo Pin
  pinMode(LED_rangeNoInput, OUTPUT);	// LED: Rangefinder input too far away
  pinMode(LED_rangeInput, OUTPUT);		// LED: Rangefinder input within range
  pinMode(LED_rangeTrigger, OUTPUT);	// LED: Rangefinder input trigger
}

// Loops
void loop() {
	// Get range and send to Pi
	range();

  panTilt();

  // Run the program 5 times per sec
  delay(200);
}

// Use rangefinder to find range in cm and send to Pi with Serial
void range() {
	// Calculate distance between RF and object
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  rawDistance = (duration/2) / 29.1; // Magic number to convert range to cm
  Serial.println(rawDistance);
  if (rawDistance < 240 || rawDistance > 12) {
    // Most readings over 2XX or under 12 are faulty or split second readings
    // since the distance loop should stop the rover at around ~26 distance

    // TODO: Smooth out distance readings

    distance = rawDistance;
  }

  if (distance < 26) {
    digitalWrite(LED_rangeTrigger,HIGH);
    digitalWrite(LED_rangeInput,LOW);
    digitalWrite(LED_rangeNoInput,LOW);
  } else if (distance < 140) {
  	digitalWrite(LED_rangeTrigger,LOW);
    digitalWrite(LED_rangeInput,HIGH);
    digitalWrite(LED_rangeNoInput,LOW);
  } else {
  	digitalWrite(LED_rangeTrigger,LOW);
    digitalWrite(LED_rangeInput,LOW);
    digitalWrite(LED_rangeNoInput,HIGH);
  }
  Serial.println(distance);
}

void movement() {

}

void capture() {
  // TODO: Send signal to pi to run photo scripts

}

void panTilt() {

  if (distance < 26) {
    // TODO: Convert delays to millis functions
    // Pan every 1.5 seconds to match photo timer
    delay(100); // Try to  sync pi timer to servo timer
    panServo.write(70);
    tiltServo.write(40);
    delay(1500);
    panServo.write(120);
    tiltServo.write(40);
    delay(1500);
    panServo.write(180);
    tiltServo.write(40);
    delay(1500);
  } else if (distance < 140){
    panServo.write(70);
    tiltServo.write(25);
  } else {
    panServo.write(0);
    tiltServo.write(50);
  }
}