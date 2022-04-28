// Basic demo for magnetometer readings from Adafruit LIS3MDL

// BUSSOLA

#include <Wire.h>
#include <Adafruit_LIS3MDL.h>
#include <Adafruit_Sensor.h>

Adafruit_LIS3MDL lis3mdl;
#define LIS3MDL_CLK 13
#define LIS3MDL_MISO 12
#define LIS3MDL_MOSI 11
#define LIS3MDL_CS 10

sensors_event_t event;

int originx;
int originy;

int targetx = 100;
int targety = 0;

int placex;
int placey;


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
int maxDistEsq = 800;

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
  valueEsq = analogRead(sensorEsq);

  placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);

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
     placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);
  } while (i < 7);

  analogWrite(motorPin2, speed);
  delay(750);
   placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);
  analogWrite(motorPin2, 0);

  do {
    straight_line();
  } while (valueEsq < 815);

  analogWrite(motorPin3, speed);
  delay(750);
   placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);
  analogWrite(motorPin3, 0);

  do {
    straight_line();
  } while (valueEsq < 815);

  analogWrite(motorPin3, speed);
  delay(750);
   placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);
  analogWrite(motorPin3, 0);

  do {
    straight_line();
  } while (valueEsq < 815);

  analogWrite(motorPin3, speed);
  delay(750);
   placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);
  analogWrite(motorPin3, 0);

  straight_line();
}

void setup(void)
{
  Serial.begin(115200);

  while (!Serial)
    delay(10);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  // Try to initialize!
  if (!lis3mdl.begin_I2C())
  { // hardware I2C mode, can pass in address & alt Wire
    // if (! lis3mdl.begin_SPI(LIS3MDL_CS)) {  // hardware SPI mode
    // if (! lis3mdl.begin_SPI(LIS3MDL_CS, LIS3MDL_CLK, LIS3MDL_MISO, LIS3MDL_MOSI)) { // soft SPI
    Serial.println("Failed to find LIS3MDL chip");
    while (1)
    {
      delay(10);
    }
  }
  Serial.println("LIS3MDL Found!");

  lis3mdl.setPerformanceMode(LIS3MDL_MEDIUMMODE);
  lis3mdl.setOperationMode(LIS3MDL_CONTINUOUSMODE);
  lis3mdl.setDataRate(LIS3MDL_DATARATE_155_HZ);
  lis3mdl.setRange(LIS3MDL_RANGE_4_GAUSS);

  lis3mdl.setIntThreshold(500);
  lis3mdl.configInterrupt(false, false, true, // enable z axis
                          true,               // polarity
                          false,              // don't latch
                          true);              // enabled!

  lis3mdl.read(); // get X Y data at once

  lis3mdl.getEvent(&event);
  /* Display the results (magnetic field is measured in uTesla) */
  originx = event.magnetic.x;
  originy = event.magnetic.y;

  targetx += originx;
  targety += originy;
}

void loop()
{
  lis3mdl.read(); // get X Y and Z data at once

  sensors_event_t event;
  lis3mdl.getEvent(&event);
  
  /* Display the results (magnetic field is measured in uTesla) */
  placex = event.magnetic.x;
  Serial.println(placex);
  placey = event.magnetic.y;
  Serial.println(placey);

  if (targetx > originx)
  {

    if (placex < targetx)
    {
      do
      {
        straight_line();
      } while (valueFrente > maxDistFrente);

      contornar();
    }
  }
else if (targetx < originx)
{
  //se ele tiver 
}
}
