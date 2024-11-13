//ESP8266 와이파이 연결 함수

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); //RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
if(mySerial.available())
{
  Serial.write(mySerial.read());
}
if(Serial.available())
{
  mySerial.write(Serial.read());
}
}



// 블링크 연결 막힌상황

#define BLYNK_TEMPLATE_ID "TMPL6uvhQLmwe"
#define BLYNK_TEMPLATE_NAME "control led2"
#define BLYNK_AUTH_TOKEN "PHO1mI-waCwWpia5PLi48F-EUI1iYH6F"

#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>

char auth[] = "PHO1mI-waCwWpia5PLi48F-EUI1iYH6F";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iPhone(57)";
char pass[] = "12345678";

// // Hardware Serial on Mega, Leonardo, Micro...
// #define EspSerial Serial1

// or Software Serial on Uno, Nano...

SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

void setup()
{

  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Serial.println("Connecting to Blynk...");
  Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8080);


  // Serial.begin(9600);
  // EspSerial.begin(ESP8266_BAUD);
  // delay(10);
  
  // // WiFi 연결 초기화
  // EspSerial.println("AT+CWQAP");  // 현재 WiFi 연결 해제
  // delay(1000);
  
  // Serial.println("Connecting to Blynk...");
  // Blynk.begin(auth, wifi, ssid, pass);


  // Serial.begin(9600);
  // EspSerial.begin(ESP8266_BAUD);
  // delay(10);
  // Serial.println("Connecting to Blynk...");
  // Blynk.begin(auth, wifi, ssid, pass);


}

void loop()
{
  Blynk.run();
  if (Blynk.connected()) {
    Serial.println("Blynk is connected!");
  } else {
    Serial.println("Blynk is not connected.");
  }
}