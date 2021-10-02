/***************************************************************************
  This is a library for the CCS811 air

  This sketch reads the sensor

  Designed specifically to work with the Adafruit CCS811 breakout
  ----> http://www.adafruit.com/products/3566

  These sensors use I2C to communicate. The device's I2C address is 0x5A

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include "Adafruit_CCS811.h"

Adafruit_CCS811 ccs;
uint8_t vocSensorState = 0;
int retryCount = 0;

void setupVOC()
{
  Serial.begin(9600);

  Serial.println("CCS811 test");

  if (!ccs.begin())
  {
    Serial.println("Failed to start sensor! Please check your wiring.");
    while (1)
    {
      vocSensorState = 0;
      break;
    }
  }

  // Wait for the sensor to be ready
  while (!ccs.available())
  {
    retryCount++;
    if (retryCount >= 15)
    {
      vocSensorState = 0;
      retryCount = 0;
      break;
    }
  }
}

String loopVOC()
{
  if (ccs.available())
  {
    if (!ccs.readData())
    {
      // Serial.print("CO2: ");
      // Serial.print(ccs.geteCO2());
      // Serial.print("ppm, TVOC: ");
      // Serial.println(ccs.getTVOC());
      co2V=String(ccs.geteCO2());
      return co2V;
    }
    else
    {
      Serial.println("ERROR!");
      //while(1);
      vocSensorState = 0;
      co2V="0.0";
      return co2V;
    }
  }
  delay(10);
}