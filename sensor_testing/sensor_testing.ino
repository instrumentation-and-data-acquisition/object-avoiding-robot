int sensor = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(sensor);
  Serial.print(value);
  Serial.print("\n");
  delay(1000);

}
