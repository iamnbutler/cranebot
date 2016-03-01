// Define Pins
#define trigPin 13
#define echoPin 12
#define noRange 11
#define inRange 10
#define tooClose 9

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(noRange, OUTPUT);
  pinMode(inRange, OUTPUT);
  pinMode(tooClose, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  // Check + Indicate distance
  if (distance < 14) {
    digitalWrite(inRange,LOW);
    digitalWrite(tooClose,HIGH);
  }
  else if (distance < 98) {
    digitalWrite(inRange,HIGH);
    digitalWrite(tooClose,LOW);
  } else {
    digitalWrite(inRange,LOW);
    digitalWrite(tooClose,LOW);
  }

  // Log distance
  if (distance >= 98 || distance <= 0){
    Serial.println("Out of range");
    digitalWrite(noRange,HIGH);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(noRange,LOW);
  }
  delay(200);
}