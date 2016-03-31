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
Servo lWheelServo;  // create servo object to control a servo
Servo rWheelServo;  // create servo object to control a servo

#define trigPin 13
#define echoPin 12
#define LED_rangeNoInput 11
#define LED_rangeInput 4
#define LED_rangeTrigger 3

// Define distances to make changing them easier
const int mediumDistance = 140;
const int closeDistance = 16;
const int minDistance = 6;

const int turnLength = 1000; // Length of the turn in millis

// Variables
int pan = 0;    // variable to read the value from the analog pin
int tilt = 0;   // variable to read the value from the analog pin
int pos = 0;

unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
long rawDistance, duration;
int distance = 0;
int lastDistance = 0;


int movementDirection = 0; // 0 = drive, 1 = reverse, 2 = turn

// Setup
void setup() {
  Serial.begin(9600);

  // Set up servos
  panServo.attach(10);  	// attaches the servo on pin 11 to the servo object
  tiltServo.attach(9);  	// attaches the servo on pin 10 to the servo object
  lWheelServo.attach(8);
  rWheelServo.attach(7);

  // Assign Pins
  pinMode(trigPin, OUTPUT); // RF Trig Pin
  pinMode(echoPin, INPUT);	// RF Echo Pin
  pinMode(LED_rangeNoInput, OUTPUT);	// LED: Rangefinder input too far away
  pinMode(LED_rangeInput, OUTPUT);		// LED: Rangefinder input within range
  pinMode(LED_rangeTrigger, OUTPUT);	// LED: Rangefinder input trigger

  tiltServo.write(60);
}

// Loops
void loop() {
	// Get range for use in loops
	range();

  if (distance < closeDistance && distance > minDistance) {
    //== Closest Distance ==//

    // .: Set distance LEDs :.
    digitalWrite(LED_rangeTrigger,HIGH);
    digitalWrite(LED_rangeInput,LOW);
    digitalWrite(LED_rangeNoInput,LOW);

    // .: Set Wheel Speed :.
    lWheelServo.write(90);  // set servo to stop
    rWheelServo.write(90);  // set servo to stop
    delay(2);

    // .: Pan camera for capture :.
    // TODO: Convert delays to millis functions
    // Pan every 1.5 seconds to match photo timer
    Serial.print("Running Camera Scripts...");
    delay(100); // Try to  sync pi timer to servo timer
    panServo.write(70);
    Serial.print(" 30...");
    delay(1500);
    // panServo.write(120);
    // Serial.print(" 60...");
    // delay(1500);
    // panServo.write(180);
    // Serial.print(" 90...");
    // delay(1500);
    // Serial.println(" Done");
  } else if (distance <= mediumDistance){
    //== Medium Distance ==//

    // .: Set distance LEDs :.
    digitalWrite(LED_rangeTrigger,LOW);
    digitalWrite(LED_rangeInput,HIGH);
    digitalWrite(LED_rangeNoInput,LOW);

    // .: Set Wheel Speed :.
    lWheelServo.write(105);  // set servo to low-speed
    rWheelServo.write(75);  // set servo to low-speed
    delay(2);

    // .: Pan camera for capture :.
    panServo.write(70);
  } else if (distance > mediumDistance) {
    //== Furthest Distance ==//

    // .: Set distance LEDs :.
    digitalWrite(LED_rangeTrigger,LOW);
    digitalWrite(LED_rangeInput,LOW);
    digitalWrite(LED_rangeNoInput,HIGH);

    // .: Set Wheel Speed :.
    lWheelServo.write(120);  // set servo to mid-speed
    rWheelServo.write(60);  // set servo to mid-speed
    delay(2);

    // .: Pan camera for capture :.
    panServo.write(0);
  }

  // Run the program 10 times per sec
  delay(100);
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

  // Constrain distance numbers to reasonable numbers
  if (rawDistance > minDistance && rawDistance < 4000) {
    // Most readings over 2XX or under 12 are faulty or split second readings
    // since the distance loop should stop the rover at around ~26 distance

    distance = rawDistance;

    // .: Smooth Distance :.
    int diff = (lastDistance - distance); // get the difference
    int diffAbs = abs(diff);
    if (diffAbs < 2.5) {
      distance = distance + (diff * 0.2); // Add a fifth of the new value to distance
    } else if (diffAbs > 20) {
      distance = distance + (diff * 0.1); // Add a tenth of the new value to distance
    }

    // Save distance for the next comparison
    lastDistance = distance;

    // Log for debugging
    Serial.print(distance);
    Serial.print(" | ");
    Serial.print(diffAbs);
    Serial.print(" | ");
    Serial.println(rawDistance);
  }
}

// void capture() {
//   // TODO: Send signal to pi to run photo scripts

// }