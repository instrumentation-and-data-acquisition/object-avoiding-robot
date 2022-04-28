
// Motor 1
const int motorPin1 = 9; // azul, direita
const int motorPin2 = 8; // amarelo
// Motor 2
const int motorPin3 = 7; // vermelho
const int motorPin4 = 6; // branco
int speed = 255;

int sensorFrente = A1;
int sensorTras = A0;
int sensorFrenteEsq = A3; // frente esquerda
int sensorFrenteDir = A5;
int sensorTrasEsq; // FALTA AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
int sensorTrasDir;

int maxDistFrente = 600;
int maxDistTras = 600;
int maxDistFrenteEsq = 600;
int maxDistFrenteDir = 600;
int maxDistTrasEsq = 600;
int maxDistTrasDir = 600;

int valueFrente;
int valueTras;
int valueFrenteEsq;
int valueFrenteDir;
int valueTrasEsq;
int valueTrasDir;

void straight_line(){

    analogWrite(motorPin2, speed);
    delay(100);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, speed);
    delay(100);
    analogWrite(motorPin3, 0);

    valueFrente = analogRead(sensorFrente);
    valueTras = analogRead(sensorTras);
    valueFrenteEsq = analogRead(sensorFrenteEsq);
    valueFrenteDir = analogRead(sensorFrenteDir);
    valueTrasEsq = analogRead(sensorTrasEsq);
    valueTrasDir = analogRead(sensorTrasDir);
    
    Serial.print("Frente: ");
    Serial.print(valueFrente);
    Serial.print("Trás: ");
    Serial.print(valueTras);
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
  pinMode(sensorTras, INPUT);
  pinMode(sensorFrenteEsq, INPUT);
  pinMode(sensorFrenteDir, INPUT);
  pinMode(sensorTrasEsq, INPUT);
  pinMode(sensorTrasDir, INPUT);

   do
  {
    straight_line();
  } while (valueFrente > maxDistFrente && valueTras > maxDistTras && valueFrenteEsq > maxDistFrenteEsq && valueFrenteDir > maxDistFrenteDir && valueTrasEsq > maxDistTrasEsq && valueTrasDir > maxDistTrasDir);
  
}
void loop()
{

}
