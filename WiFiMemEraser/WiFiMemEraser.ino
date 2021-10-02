
#include <WiFi.h>
#include <WebServer.h>
#include <AutoConnect.h>
void deleteAllCredentials(void) {
  AutoConnectCredential credential;
  station_config_t config;
  uint8_t ent = credential.entries();

  while (ent--) {
    credential.load(0, &config);
    credential.del((const char*)&config.ssid[0]);
  }
}

void setup(){
    Serial.begin(115200);
    Serial.print("Removing Creds");
    deleteAllCredentials();
}

void loop(){
    delay(1000);
}