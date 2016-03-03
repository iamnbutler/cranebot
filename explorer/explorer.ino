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
#define LED_rangeNoInput 7
#define LED_rangeInput 6
#define LED_rangeTrigger 5

// Variables
int pan;    // variable to read the value from the analog pin
int tilt;   // variable to read the value from the analog pin

// Setup
void setup() {
  Serial.begin(9600);

  // Set up servos
  panServo.attach(11);  	// attaches the servo on pin 11 to the servo object
  tiltServo.attach(10);  	// attaches the servo on pin 10 to the servo object

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

  // Run the program 5 times per sec
  delay(200);
}

// Use rangefinder to find range in cm and send to Pi with Serial
void range() {
	// Calculate distance between RF and object
	long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; // Magic number to convert range to cm

  // Check distance and indicate with LEDs
  if (distance < 14) {
    digitalWrite(LED_rangeTrigger,HIGH);
    digitalWrite(LED_rangeInput,LOW);
    digitalWrite(LED_rangeNoInput,LOW);
  } else if (distance < 98) {
  	digitalWrite(LED_rangeTrigger,LOW);
    digitalWrite(LED_rangeInput,HIGH);
    digitalWrite(LED_rangeNoInput,LOW);
  } else {
  	digitalWrite(LED_rangeTrigger,LOW);
    digitalWrite(LED_rangeInput,LOW);
    digitalWrite(LED_rangeNoInput,HIGH);
  }

  // Send range to Pi
	Serial.println(distance);
}