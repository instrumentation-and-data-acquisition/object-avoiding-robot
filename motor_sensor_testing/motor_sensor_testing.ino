
// Motor 1
const int motorPin1 = 9; // amarelo
const int motorPin2 = 8; // amarelo
// Motor 2
const int motorPin3 = 7; // vermelho direita
const int motorPin4 = 6; // branco
int speed = 255;

// SENSOR DE DISTâNCIA FRENTE
int sensorFrente = A2;
int sensorEsq = A1; // frente esquerda

int maxDistFrente = 650;
int maxDistEsq = 650;

int valueFrente;
int valueEsq;

void straight_line()
{

  analogWrite(motorPin2, speed);
  delay(100);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, speed);
  delay(100);
  analogWrite(motorPin3, 0);

  valueFrente = analogRead(sensorFrente);
  Serial.print("Frente: ");
  Serial.print(valueFrente);
  valueEsq = analogRead(sensorEsq);
  Serial.print(" Esquerda: ");
  Serial.println(valueEsq);
}

void contornar()
{

  int i = 0;

  do
  {
    analogWrite(motorPin1, speed);
    delay(100);
    analogWrite(motorPin1, 0);
    analogWrite(motorPin4, speed);
    delay(100);
    analogWrite(motorPin4, 0);
    i++;
  } while (i < 7);

  analogWrite(motorPin2, speed);
  delay(750);
  analogWrite(motorPin2, 0);

  i = 0;

  while (i < 7)
  {

    straight_line();
    i++;
  }

  analogWrite(motorPin3, speed);
  delay(750);
  analogWrite(motorPin3, 0);

  i = 0;

  while (i < 28)
  {

    straight_line();
    i++;
  }

  analogWrite(motorPin3, speed);
  delay(750);
  analogWrite(motorPin3, 0);

  i = 0;

  while (i < 7)
  {

    straight_line();
    i++;
  }

  analogWrite(motorPin3, speed);
  delay(750);
  analogWrite(motorPin3, 0);

  straight_line();
}

void setup()
{
  Serial.begin(9600);
  // Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(sensorFrente, INPUT);
  pinMode(sensorEsq, INPUT);

  do
  {
    straight_line();
  } while (valueFrente > maxDistFrente);

  contornar();
}
void loop()
{
}
