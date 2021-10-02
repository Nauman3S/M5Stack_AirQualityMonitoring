/* Test sketch for Adafruit PM2.5 sensor with UART or I2C */

#include "Adafruit_PM25AQI.h"

// If your PM2.5 is UART only, for UNO and others (without hardware serial)
// we must use software serial...
// pin #2 is IN from sensor (TX pin on sensor), leave pin #3 disconnected
// comment these two lines if using hardware serial
//#include <SoftwareSerial.h>
//SoftwareSerial pmSerial(2, 3);

Adafruit_PM25AQI aqi = Adafruit_PM25AQI();
uint8_t pm5State = 0;
void setupPM5()
{
  // Wait for serial monitor to open
  Serial.begin(115200);
  while (!Serial)
    delay(10);

  Serial.println("Adafruit PMSA003I Air Quality Sensor");

  // Wait one second for sensor to boot up!
  delay(1000);

  // If using serial, initialize it and set baudrate before starting!
  // Uncomment one of the following
  //Serial1.begin(9600);
  //pmSerial.begin(9600);

  // There are 3 options for connectivity!
  if (!aqi.begin_I2C())
  { // connect to the sensor over I2C
    //if (! aqi.begin_UART(&Serial1)) { // connect to the sensor over hardware serial
    //if (! aqi.begin_UART(&pmSerial)) { // connect to the sensor over software serial
    Serial.println("Could not find PM 2.5 sensor!");
    while (1)
    {
      pm5State = 0;
      delay(100);
      break;
    }
  }

  Serial.println("PM25 found!");
}

String loopPM5()
{
  PM25_AQI_Data data;

  if (!aqi.read(&data))
  {
    Serial.println("Could not read from AQI");
    delay(500); // try again in a bit!
    pm5State = 0;
    pm2V="0.0";
    return pm2V;
  }
  else
  {
    // Serial.println("AQI reading success");

    // Serial.println();
    // Serial.println(F("---------------------------------------"));
    // Serial.println(F("Concentration Units (standard)"));
    // Serial.println(F("---------------------------------------"));
    // Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_standard);
    // Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_standard);
    // Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_standard);
    // Serial.println(F("Concentration Units (environmental)"));
    // Serial.println(F("---------------------------------------"));
    // Serial.print(F("PM 1.0: ")); Serial.print(data.pm10_env);
    // Serial.print(F("\t\tPM 2.5: ")); Serial.print(data.pm25_env);
    // Serial.print(F("\t\tPM 10: ")); Serial.println(data.pm100_env);
    // Serial.println(F("---------------------------------------"));
    // Serial.print(F("Particles > 0.3um / 0.1L air:")); Serial.println(data.particles_03um);
    // Serial.print(F("Particles > 0.5um / 0.1L air:")); Serial.println(data.particles_05um);
    // Serial.print(F("Particles > 1.0um / 0.1L air:")); Serial.println(data.particles_10um);
    // Serial.print(F("Particles > 2.5um / 0.1L air:")); Serial.println(data.particles_25um);
    // Serial.print(F("Particles > 5.0um / 0.1L air:")); Serial.println(data.particles_50um);
    // Serial.print(F("Particles > 10 um / 0.1L air:")); Serial.println(data.particles_100um);
    // Serial.println(F("---------------------------------------"));
    pm2V= String(data.particles_25um);
    return pm2V;

    delay(10);
  }
}