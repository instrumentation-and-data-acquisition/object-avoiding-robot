
// Motor 1
const int motorPin1 = 9; // azul, direita
const int motorPin2 = 8; // amarelo
// Motor 2
const int motorPin3 = 7; // vermelho
const int motorPin4 = 6; // branco
int speed = 255;

int sensorFrente = A2;
int sensorEsq = A1; // frente esquerda

int maxDistFrente = 600;
int maxDistEsq = 600;

int valueFrente;
int valueEsq;

void straight_line(){

    analogWrite(motorPin1, speed);
    delay(100);
    analogWrite(motorPin1, 0);
    analogWrite(motorPin4, speed);
    delay(100);
    analogWrite(motorPin4, 0);

    valueFrente = analogRead(sensorFrente);
    valueEsq = analogRead(sensorEsq);
    
    Serial.print("Frente: ");
    Serial.print(valueFrente);
    Serial.print("\n");
  
  
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
  } while (valueFrente > maxDistFrente && valueEsq > maxDistEsq);
  
}
void loop()
{

}
