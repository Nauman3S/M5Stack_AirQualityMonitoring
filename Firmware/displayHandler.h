/*


A few colour codes:

code	color
0x0000	Black
0xFFFF	White
0xBDF7	Light Gray
0x7BEF	Dark Gray
0xF800	Red
0xFFE0	Yellow
0xFBE0	Orange
0x79E0	Brown
0x7E0	Green
0x7FF	Cyan
0x1F	Blue
0xF81F	Pink

 */
#include "Free_Fonts.h"
#define TFT_GREY 0x5AEB
#define LIGHT_GREY 0x5AEB

uint32_t targetTime = 0; // for next 1 second timeout

byte omm = 99, oss = 99;
byte xcolon = 0, xsecs = 0;
unsigned int colour = 0;

uint8_t screenStatus = 0;
uint8_t activeScreen = 0;
//320x240
void setupDISPLAY(void)
{

    // M5.Lcd.setRotation(1);
    M5.Lcd.fillScreen(TFT_BLACK);

    M5.Lcd.setTextSize(1);
    M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);

    M5.Lcd.setBrightness(255);

    M5.Lcd.drawRect(130, 11, 10, 10, BLUE);
    M5.Lcd.fillCircle(160, 13, 5, WHITE);
    M5.Lcd.fillCircle(190, 13, 5, WHITE);

    targetTime = millis() + 1000;
}
void displayBatteryLevel(uint8_t val)
{
    if (M5.Power.isCharging() == 0)
    {
        M5.Lcd.drawRect(275, 10, 5, 5, BLUE);
        M5.Lcd.progressBar(280, 8, 40, 10, val);
    }
    else
    {
        M5.Lcd.drawRect(275, 10, 5, 5, GREEN);
        M5.Lcd.progressBar(280, 8, 40, 10, val);
    }
}

void screenHandler()
{
    int xpos = 10;
    int ypos = 85;
    if (activeScreen == 0)
    { //Co2
        M5.Lcd.drawFloat(23.56, 2, xpos, ypos, 8);
        M5.Lcd.setCursor(xpos + 20, ypos + 130);
        M5.Lcd.setFreeFont(FSB24);
        M5.Lcd.print("Co2");
    }
    else if (activeScreen == 1)
    {
        //PM2.5
        M5.Lcd.drawFloat(23.56, 2, xpos, ypos, 8);
        M5.Lcd.setCursor(xpos + 20, ypos + 130);
        M5.Lcd.setFreeFont(FSB24);
        M5.Lcd.print("PM2.5");
    }
    else if(activeScreen == 2){
        M5.Lcd.setCursor(10, 60);
        M5.Lcd.setFreeFont(FSB24);
        M5.Lcd.print("Settings");
    }
}
void btnHandler()
{
    //btn1 turn on/off ; btn2 switch screens,; btn3 N/A

    if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200))
    {
        if (screenStatus == 0)
        {
            M5.Lcd.setBrightness(255);
            screenStatus = 1;
        }
        else if (screenStatus == 1)
        {
            screenStatus = 0;
            M5.Lcd.setBrightness(0);
        }
    }
    else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200))
    {
        M5.Lcd.clear(TFT_BLACK);
        
        if (activeScreen == 0)
        {
            
            M5.Lcd.drawRect(130, 11, 10, 10, BLUE);
            M5.Lcd.fillCircle(160, 13, 5, WHITE);
            M5.Lcd.fillCircle(190, 13, 5, WHITE);
            activeScreen++;
            
        }

        else if (activeScreen == 2)
        {
            
            M5.Lcd.fillCircle(130, 13, 5, WHITE);
            M5.Lcd.drawRect(160, 11, 10, 10, BLUE);
            M5.Lcd.fillCircle(190, 13, 5, WHITE);
            
            activeScreen = 0;
        }
        else if (activeScreen == 1)
        {

            M5.Lcd.fillCircle(130, 13, 5, WHITE);
            M5.Lcd.fillCircle(160, 13, 5, WHITE);
            M5.Lcd.drawRect(190, 11, 10, 10, BLUE);
            
            activeScreen++;
        }
    }
    else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200))
    {
        M5.Lcd.print('C');
    }
    else if (M5.BtnB.wasReleasefor(700))
    {
        // M5.Lcd.clear(WHITE); // Clear the screen and set white to the background color.  清空屏幕并将白色设置为底色
        // M5.Lcd.setCursor(0, 0);
    }
}
void loopDisplay()
{
    M5.update();
    btnHandler();

    displayBatteryLevel(M5.Power.getBatteryLevel());

    if (targetTime < millis())
    {

        // Set next update for 1 second later

        targetTime = millis() + 1000;

        screenHandler();
    }
}
