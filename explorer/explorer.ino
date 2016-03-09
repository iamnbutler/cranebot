#include <DRV8835MotorShield.h>

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

DRV8835MotorShield motors;

// Variables
int pan = 0;    // variable to read the value from the analog pin
int tilt = 0;   // variable to read the value from the analog pin

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

int movementDirection = 0; // 0 = drive, 1 = reverse, 2 = turn

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
	// range();

  movement();

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

void movement() {

  if (movementDirection = 0) {
    if (distance > 98) {
      motors.setM1Speed(140);
      motors.setM2Speed(140);
      delay(2);
    } else if (distance > 14) {
      motors.setM1Speed(70);
      motors.setM2Speed(70 );
    } else {
      motors.setM1Speed(0);
      motors.setM2Speed(0);
      capture();
      delay(1200);
      movementDirection = 1;
    }
    Serial.println('drive');
  }

  if (movementDirection = 1) {
    motors.setM1Speed(-70);
    motors.setM2Speed(-70);
    if (distance > 98) {
      motors.setM1Speed(0);
      motors.setM2Speed(0);
      delay(1200);
      movementDirection = 2;
      previousMillis = millis();
    }
    Serial.println('reverse');
  }

  if (movementDirection = 2) {
    // Turn until x millis have passed
    currentMillis = millis();
    motors.setM1Speed(70);
    motors.setM2Speed(-70);

    if ((currentMillis - previousMillis) > turnLength) {
      // Stop turning and move forward
      movementDirection = 0;
    }

    Serial.println('turn');
  }
}

void capture() {
  // TODO: Send signal to pi to run photo scripts
}