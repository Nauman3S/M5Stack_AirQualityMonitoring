int fanPin=26;
void setupFanHandler(int fanPinV){
    fanPin=fanPinV;
    pinMode(fanPin, OUTPUT);
}

void fanSwitch(uint8_t state){
    if(state==0){
        digitalWrite(fanPin,LOW);
    }
    else if (state==1)
    {
        digitalWrite(fanPin,HIGH);
    }
}