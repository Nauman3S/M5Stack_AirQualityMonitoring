#include <M5Stack.h>
#include "displayHandler.h"
#include "headers.h"   //all misc. headers and functions
#include "MQTTFuncs.h" //MQTT related functions
   //Captive Portal webpages

IPAddress ipV(192, 168, 4, 1);

uint8_t inAP = 0;
bool whileCP()
{

    loopDisplay();

    if (inAP == 0)
    {

        inAP = 1;
    }
    // Serial.println("AP MODE");
}

/* After M5Core is started or reset
the program in the setUp () function will be run, and this part will only be run once.
After M5Core is started or reset, it will start to execute the program in the setup() function, and this part will only be executed once. */
void setup()
{

    M5.begin();       //Init M5Core. Initialize M5Core
    M5.Power.begin(); //Init Power module. Initialize the power module
    setupDISPLAY();
    /* Power chip connected to gpio21, gpio22, I2C device
                      Set battery charging voltage and current
                      If used battery, please call this function in your project */

    if (!MDNS.begin("esp32")) //starting mdns so that user can access webpage using url `esp32.local`(will not work on all devices)
    {
        Serial.println("Error setting up MDNS responder!");
        while (1)
        {
            delay(1000);
        }
    }

    server.on("/", handleRoot);
    server.on("/io", handleGPIO);
    portal.onDetect(atDetect);
    portal.whileCaptivePortal(whileCP);
    if (portal.begin())
    {
        Serial.println("Started, IP:" + WiFi.localIP().toString());
    }
    else
    {
        Serial.println("Connection failed.");
        while (true)
        {
            yield();
        }
    }
}

// /* After the program in setup() runs, it runs the program in loop()
// The loop() function is an infinite loop in which the program runs repeatedly
// After the program in the setup() function is executed, the program in the loop() function will be executed
// The loop() function is an endless loop, in which the program will continue to run repeatedly */
void loop()
{
    loopDisplay();
    server.handleClient();
    portal.handleRequest();
    if (WiFi.status() == WL_IDLE_STATUS)
    {

        ESP.restart();

        delay(1000);
    }
}