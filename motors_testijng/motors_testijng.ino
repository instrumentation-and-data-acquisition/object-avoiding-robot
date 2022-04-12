//Motor 1
const int motorPin1 = 9;
const int motorPin2 = 8;
//Motor 2
const int motorPin3 = 7;
const int motorPin4 = 6;
int speed = 255;
void setup(){
//Set pins as outputs
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
//Motor Control A in both directions

}
void loop(){
  analogWrite(motorPin1, speed);
  delay(25);
  analogWrite(motorPin1, 0);
  delay(1);
  analogWrite(motorPin2, speed);
  delay(25);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, speed);
  delay(25);
  analogWrite(motorPin3, 0);
  delay(1);
  analogWrite(motorPin4, speed);
  delay(25);
  analogWrite(motorPin4, 0);
  
  
}
