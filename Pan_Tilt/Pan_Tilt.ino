#include <Servo.h> 

Servo panservo;
Servo tiltservo;

const int maxpan = 180;
const int minpan = 1800;
const int maxtilt = 180;
const int mintilt = 45;

int pan = 100;
int tilt = 100;
void setup() {
  // put your setup code here, to run once:
panservo.attach(8);  
  tiltservo.attach(9);
  panservo.write(pan);
  tiltservo.write(tilt);

  Serial.begin(115200);
  Serial.println("ready");
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available() > 0){
    int input = Serial.read();

   /* if(input == 'a'){
      if((pan + 5) < maxpan) pan += 5;
    }

    if(input == 'd'){
      if((pan - 5) > minpan) pan -= 5;
    }

    if(input == 's'){
      if((tilt + 5 ) < maxtilt) tilt += 5;
    }

    if(input == 'w'){
      if((tilt - 5 ) > mintilt) tilt -= 5;
    }*/

    if(input == 'p'){
      for(int i = minpan ; i < maxpan ; i++) {
        panservo.write(i);
        delay(35);
      }
      for(int i = maxpan ; i > minpan ; i--) {
        panservo.write(i);
        delay(35);
      }
    }

    if(input == 'o'){ // turn off motors 
      panservo.detach();
      tiltservo.detach();
    }

    panservo.write(pan);
    tiltservo.write(tilt);
    Serial.println("pan: " + (String)pan + " tilt: " + (String)tilt);
  }
}

