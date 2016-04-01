unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
long rawDistance, duration;
int distance = 0;
int lastDistance = 0;

void setup() {
	Serial.begin(9600); // use the same baud-rate as the python side
	// Assign Pins
  pinMode(trigPin, OUTPUT); // RF Trig Pin
  pinMode(echoPin, INPUT);	// RF Echo Pin
}
void loop() {

	digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  rawDistance = (duration/2) / 29.1; // Magic number to convert range to cm
  Serial.println(rawDistance); // write a string

	delay(988);
}