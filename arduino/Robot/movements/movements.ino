int mode = 0; // 0 = fear, 1 = aggression, 2 = love
int leftEye = 0;
int rightEye = 0;
int leftWheelSpeed = 0;
int rightWheelSpeed = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  
  // put your main code here, to run repeatedly:
leftEye = analogRead(0);
rightEye = analogRead(1);

Serial.println(leftEye);

//

//map & constrain
 switch(mode) {
    case 0:
    //fear(leftEye, rightEye);
    leftWheelSpeed = map(leftEye, 0, 100, 0, 400);
    rightWheelSpeed = map(rightEye, 0, 100, 0, 400);
    break;
    case 1:
    //aggression(leftEye, rightEye);
    leftWheelSpeed = map(leftEye, 0, 100, 0, 400);
    rightWheelSpeed = map(rightEye, 0, 100, 0, 400);
    break;
    case 2:
    //love(leftEye, rightEye);
    leftWheelSpeed = map(leftEye, 0, 100, 0, 400);
    rightWheelSpeed = map(rightEye, 0, 100, 0, 400);
    break;
    default:
    //curiosity
    leftWheelSpeed = map(leftEye, 0, 100, 0, 400);
    rightWheelSpeed = map(rightEye, 0, 100, 0, 400);
    break;
  }
  // set wheel speeds
 // motors.setM1Speed(leftWheelSpeed); //we dont have moteor object.
  //motors.setM2Speed(rightWheelSpeed);
}
