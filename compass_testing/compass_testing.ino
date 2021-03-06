// Basic demo for magnetometer readings from Adafruit LIS3MDL

//BUSSOLA

#include <Wire.h>
#include <Adafruit_LIS3MDL.h>
#include <Adafruit_Sensor.h>

Adafruit_LIS3MDL lis3mdl;
#define LIS3MDL_CLK 13
#define LIS3MDL_MISO 12
#define LIS3MDL_MOSI 11
#define LIS3MDL_CS 10

int originx;
int originy;

int targetx = 10;
int targety = 0;

int placex;
int placey;


void setup(void) {
  Serial.begin(115200);
  
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit LIS3MDL test!");
  
  // Try to initialize!
  if (! lis3mdl.begin_I2C()) {          // hardware I2C mode, can pass in address & alt Wire
  //if (! lis3mdl.begin_SPI(LIS3MDL_CS)) {  // hardware SPI mode
  //if (! lis3mdl.begin_SPI(LIS3MDL_CS, LIS3MDL_CLK, LIS3MDL_MISO, LIS3MDL_MOSI)) { // soft SPI
    Serial.println("Failed to find LIS3MDL chip");
    while (1) { delay(10); }
  }
  Serial.println("LIS3MDL Found!");

  lis3mdl.setPerformanceMode(LIS3MDL_MEDIUMMODE);
  lis3mdl.setOperationMode(LIS3MDL_CONTINUOUSMODE);
  lis3mdl.setDataRate(LIS3MDL_DATARATE_155_HZ);
  lis3mdl.setRange(LIS3MDL_RANGE_4_GAUSS);

  lis3mdl.setIntThreshold(500);
  lis3mdl.configInterrupt(false, false, true, // enable z axis
                          true, // polarity
                          false, // don't latch
                          true); // enabled!

  lis3mdl.read();      // get X Y data at once
  sensors_event_t event; 
  lis3mdl.getEvent(&event);
  /* Display the results (magnetic field is measured in uTesla) */
  originx = event.magnetic.x;
  originy = event.magnetic.y;

  targetx += originx;
  targety += originy;
}

void loop() {
  lis3mdl.read();      // get X Y and Z data at once

  /* Or....get a new sensor event, normalized to uTesla */
  sensors_event_t event; 
  lis3mdl.getEvent(&event);
  /* Display the results (magnetic field is measured in uTesla) */
  placex = event.magnetic.x;
  Serial.print("\tX: "); Serial.print(placex);
  placey = event.magnetic.y;
  Serial.print(" \tY: "); Serial.print(placey);  
  Serial.println(" uTesla ");

 
}
