int sensor = A2;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  
  }

  void loop()
  {
    // put your main code here, to run repeatedly:
    int value = analogRead(sensor);
    Serial.print(value);
    Serial.print("\n");
    delay(1000);
  }
