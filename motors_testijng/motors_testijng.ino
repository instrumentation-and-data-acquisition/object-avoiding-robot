int motor1 = A0;
int motor2 = A1;

int i = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    analogWrite(motor1, 255);
    analogWrite(motor2, 255);


}
