int fanPin = 26;
uint8_t fanState = 0;
uint8_t getFanState(){
    return fanState;
}
void setupFanHandler(int fanPinV)
{
    fanPin = fanPinV;

    pinMode(fanPin, OUTPUT);
}

void fanSwitch(uint8_t state)
{
    fanState = state;
    if (state == 0)
    {

        digitalWrite(fanPin, LOW);
    }
    else if (state == 1)
    {
        digitalWrite(fanPin, HIGH);
    }
}