
String hostName = "SmartAir";
#include <WiFi.h>
#include <WebServer.h>
#include <AutoConnect.h>

#include <ESPmDNS.h>
#include <PubSubClient.h>
#include "SoftwareStack.h"
#include "neoTimer.h"
WebServer server;
#include "webApp.h"

#define GET_CHIPID() ((uint16_t)(ESP.getEfuseMac() >> 32))

unsigned long lastPub = 0;
unsigned int updateInterval = 2000;

SoftwareStack ss; //SS instance
AutoConnectConfig config;
AutoConnect portal(server);

String loggedIn = "";

String mac = (WiFi.macAddress());
char __mac[sizeof(mac)];

const char *mqtt_server = "broker.hivemq.com";
IPAddress mqttBroker(34, 214, 65, 82);
const int mqtt_port = 1883;
const char *mqtt_user = "testUser";
const char *mqtt_pass = "testUser@123";
const char *mqtt_client_name = __mac; //"12312312312332212";// any random alphanumeric stirng
//////////////////////////////
#define BUFFER_SIZE 250
String incoming = "";
String incomingTopic = "";
WiFiClient wclient;
PubSubClient mqttClient(wclient);

String devList[10];
String IMEIsList[10];
String LastUpdated = "";
String internetStatus = "Not-Connected";
int selectedDeviceIndex = 0;
String connectionMode = "WiFi";

bool atDetect(IPAddress &softapIP)
{
  Serial.println("Captive portal started, SoftAP IP:" + softapIP.toString());

  return true;
}
