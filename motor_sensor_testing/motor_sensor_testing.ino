
// Motor 1
const int motorPin1 = 9; // amarelo direita?
const int motorPin2 = 8; // amarelo
// Motor 2
const int motorPin3 = 7; // vermelho
const int motorPin4 = 6; // branco
int speed = 255;

const int PhotoIn = 2;
int State = 0;

int pilha = 3;

// 5 é 1 com 2 em paralelo com 2 em paralelo

// SENSOR DE DISTâNCIA FRENTE
int sensorFrente = A1;
int sensorTras = A0;
int sensorFrenteEsq = A3; // frente esquerda
int sensorFrenteDir = A5;

int maxDistFrente = 600;
int maxDistTras = 500;
int maxDistFrenteEsq = 600;
int maxDistFrenteDir = 600;

int valueFrente;
int valueTras;
int valueFrenteEsq;
int valueFrenteDir;

void contornar(){
  do {
  analogWrite(motorPin2, speed); //vira direita
  delay(130);
  analogWrite(motorPin2, 0);
  valueFrenteEsq = analogRead(sensorFrenteEsq);
  Serial.print("Frente esq: ");
  Serial.print(valueFrenteEsq);
  valueFrente = analogRead(sensorFrente);
  Serial.print(" Frente: ");
  Serial.print(valueFrente);
  valueFrenteDir = analogRead(sensorFrenteDir);
  Serial.print(" Frente Dir: ");
  Serial.print(valueFrenteDir);
  Serial.print("\n");
  } while(valueFrenteEsq <= 800 || valueFrente <= 800 || valueFrenteDir <= 800);
  
}

void setup()
{
  Serial.begin(9600);
  // Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(PhotoIn, INPUT);
  pinMode(sensorFrente, INPUT);
  pinMode(sensorTras, INPUT);
  pinMode(sensorFrenteEsq, INPUT);
  pinMode(sensorFrenteDir, INPUT);

   do
  {
    analogWrite(motorPin2, speed);
    delay(100);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, speed);
    delay(100);
    analogWrite(motorPin3, 0);

    valueFrente = analogRead(sensorFrente);
    valueTras = analogRead(sensorTras);

    Serial.print("frente");
    
//    Serial.print("Frente: ");
//    Serial.print(valueFrente);
//    Serial.print("Trás: ");
//    Serial.print(valueTras);
//    Serial.print("\n");
  } while (valueFrente > maxDistFrente && valueTras > maxDistTras);

  contornar();

    //analogWrite(motorPin2, speed);
    //delay(3000/pilha);
    //analogWrite(motorPin2, 0);

//    int i = 0;
//
//    while (i < 5){
//  
//      analogWrite(motorPin2, speed);
//      delay(130);
//      analogWrite(motorPin2, 0);
//      analogWrite(motorPin3, speed);
//      delay(100);
//      analogWrite(motorPin3, 0);
//
//      i+=1;
//
//    }
//
//    analogWrite(motorPin3, speed);
//    delay(3000/2/pilha);
//    analogWrite(motorPin3, 0);
//
//    while (i < 5){
//  
//      analogWrite(motorPin2, speed);
//      delay(130);
//      analogWrite(motorPin2, 0);
//      analogWrite(motorPin3, speed);
//      delay(100);
//      analogWrite(motorPin3, 0);
//
//      i+=1;
//
//    }
//
//    analogWrite(motorPin3, speed);
//    delay(3000/2/pilha);
//    analogWrite(motorPin3, 0);
//
//    while (i < 5){
//  
//      analogWrite(motorPin2, speed);
//      delay(130);
//      analogWrite(motorPin2, 0);
//      analogWrite(motorPin3, speed);
//      delay(100);
//      analogWrite(motorPin3, 0);
//
//      i+=1;
//
//    }
//
//    analogWrite(motorPin2, speed);
//    delay(3000/pilha);
//    analogWrite(motorPin2, 0);
//
//    while (i < 50){
//  
//      analogWrite(motorPin2, speed);
//      delay(130);
//      analogWrite(motorPin2, 0);
//      analogWrite(motorPin3, speed);
//      delay(100);
//      analogWrite(motorPin3, 0);
//
//      i+=1;
//
//    }
  
}
void loop()
{

}
