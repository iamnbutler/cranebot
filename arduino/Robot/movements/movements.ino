//Arduino PLL Speed Control：
int E1 = 4;   
int M1 = 5;
int E2 = 7;                         
int M2 = 6;  
int leftWheelSpeed = 0;
int rightWheelSpeed = 0;
                         
 
void setup() 
{ 
    pinMode(M1, OUTPUT);   
    pinMode(M2, OUTPUT); 
    pinMode(E1, OUTPUT); 
    pinMode(E2, OUTPUT); 
} 
 
void loop() 
{ 
  int value;
  for(value = 0 ; value <= 255; value+=5) 
  { 
    digitalWrite(E1,HIGH);   
    digitalWrite(E2, HIGH);       
    analogWrite(M1, value);   //PLL Speed Control
    analogWrite(M2, value);   //PLL Speed Control
    delay(30); 
  }  
}
