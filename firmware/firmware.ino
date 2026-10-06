// RePower Firmware 1.0

#include <RCSwitch.h>
#include <WiFi.h>
#include <WebServer.h>

#define OPT_IN2 1
#define OPT_IN1 2
#define RF_DATA 3
#define LED 4
#define EXTERNAL_BTN 5

const unsigned long RF_POWER = 4523101; // replace
const unsigned long RF_RESET = 4523102; // replace

const char* ssid = "ssid";
const char* password = "pass";

RCSwitch RF = RCSwitch();
  
const char PAGE[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>RePower</title>
<style>
body {
  background: #141414;
  color: white;
  font-family: sans-serif;
  text-align: center;
  padding-top: 20vh;
}
h1 {
  font-size: 2rem;
  margin-bottom: 30px;
}
button {
  display: block;
  width: 260px;
  margin: 16px auto;
  padding: 20px;
  font-size: 20px;
  font-weight: bold;
  color: white;
  border: none;
  border-radius: 10px;
  cursor: pointer;
}
.power {
  background: #1e7e34;
}
.power:active {
  background: #155724;
}
.reset {
  background: #bd2130;
}
.reset:active {
  background: #8b1823;
}
</style>
</head>
<body>
<h1>RePower</h1>
<button class="power" onclick="fetch('/power')">Power</button>
<button class="reset" onclick="fetch('/reset')">Reset</button>
</body>
</html>
)rawliteral";

WebServer server(80);

void trigger(int pin) {
  digitalWrite(LED, HIGH);
  digitalWrite(pin, HIGH);
  delay(300);
  digitalWrite(pin, LOW);
  digitalWrite(LED, LOW);
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Setting up pins");

    pinMode(OPT_IN2, OUTPUT);
    pinMode(OPT_IN1, OUTPUT);
    pinMode(LED, OUTPUT);

    digitalWrite(OPT_IN1, LOW);
    digitalWrite(OPT_IN2, LOW);
    digitalWrite(LED, LOW);

    pinMode(EXTERNAL_BTN, INPUT_PULLUP);

    RF.enableReceive(digitalPinToInterrupt(RF_DATA));

    Serial.println("Pins ready");
    
    WiFi.begin(ssid, password);
    Serial.print("Connecting to wifi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to wifi");
    Serial.print("IP address:");
    Serial.println(WiFi.localIP());

    server.on("/", []() {
      server.send(200, "text/html", PAGE);
    });

    server.on("/power", []() {
      Serial.println("Power");
      trigger(OPT_IN1);
      server.send(200, "text/plain", "OK");
    });

    server.on("/reset", []() {
      Serial.println("Reset");
      trigger(OPT_IN2);
      server.send(200, "text/plain", "OK");
    });

    server.begin();
    Serial.println("\nServer started");
}

void loop()
{
    server.handleClient();

    if (RF.available()) {
    unsigned long receivedValue = RF.getReceivedValue();
    Serial.print("Received:");
    Serial.println(receivedValue);

    if (receivedValue == RF_POWER) {
      Serial.println("Power");
      trigger(OPT_IN1);
    } else if (receivedValue == RF_RESET) {
      Serial.println("Reset");
      trigger(OPT_IN2);
    }

    RF.resetAvailable();
  }
    static int lastBtnState = HIGH;
    int currentBtnState = digitalRead(EXTERNAL_BTN);
    if (currentBtnState == LOW && lastBtnState == HIGH) {
      delay(50);
      if (digitalRead(EXTERNAL_BTN) == LOW) {
        Serial.println("Power");
        trigger(OPT_IN1);
      }
    }
    lastBtnState = currentBtnState;
}
