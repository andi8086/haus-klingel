
#include <WiFi.h>
#include <AsyncUDP.h>

const char *ssid = "SSID";
const char *pw = "WLAN PW";

AsyncUDP udp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pw);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to Wifi\n");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Gateway IP: ");
  Serial.println(WiFi.gatewayIP());

  pinMode(14, INPUT_PULLDOWN);
  pinMode(12, OUTPUT);

  digitalWrite(12, HIGH);

}


bool door_bell_button = false;

void loop() {
  // put your main code here, to run repeatedly:
  door_bell_button = digitalRead(14) == HIGH;
  delay(50);
  if (door_bell_button) {
    if (door_bell_button && (digitalRead(14) == HIGH)) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(12, LOW);
        delay(250);
        udp.broadcastTo("dingdong", 12345);
        digitalWrite(12, HIGH);
        delay(250);
      }
    }
  }
}
