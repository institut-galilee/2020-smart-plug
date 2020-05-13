#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

const char *ssid = "Geny";
const char *password = "lancer123";

const int relay = 2;
const int capteurElectricite = 34;

int valeurDelayOn = 1000;
bool etatrelay = 0;
bool etatrelayVoulu = 0;
int previousMillis = 0;
int valeurDelayOf =0;
String valeurdemM;
String valeurdemH;
String valeurcoupM;
String valeurcoupH;


AsyncWebServer server(80);

void setup()
{
  //----------------------------------------------------Serial
  Serial.begin(115200);
  Serial.println("\n");

  //----------------------------------------------------GPIO
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  pinMode(capteurElectricite, INPUT);

  //----------------------------------------------------SPIFFS
  if (!SPIFFS.begin())
  {
    Serial.println("Erreur SPIFFS...");
    return;
  }

  File root = SPIFFS.open("/");
  File file = root.openNextFile();

  while (file)
  {
    Serial.print("File: ");
    Serial.println(file.name());
    file.close();
    file = root.openNextFile();
  }

  //----------------------------------------------------WIFI
  WiFi.begin(ssid, password);
  Serial.print("Tentative de connexion...");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\n");
  Serial.println("Connexion etablie!");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());

  //----------------------------------------------------SERVER
  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/w3.css", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/w3.css", "text/css");
  });

  server.on("/script.js", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server.on("/jquery-3.5.1.min.js", HTTP_POST, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/jquery-3.5.1.min.js", "text/javascript");
  });

  server.on("/lireElectricite", HTTP_POST, [](AsyncWebServerRequest *request) {
    int val = analogRead(capteurElectricite);
    String electr = String(val);
    request->send(200, "text/plain", electr);
  });

  server.on("/on", HTTP_POST, [](AsyncWebServerRequest *request) {
    etatrelayVoulu = 1;
    request->send(204);
  });

  server.on("/off", HTTP_POST, [](AsyncWebServerRequest *request) {
    etatrelayVoulu = 0;
    digitalWrite(relay, LOW);
    etatrelay = 0;
    request->send(204);
  });

  server.on("/delayOnOf", HTTP_POST, [](AsyncWebServerRequest *request) {
    if(request->hasParam("valeurDelayON", true))
    {
      String message;
      message = request->getParam("valeurDelayON", true)->value();
      valeurDelayOn = message.toInt();
    
    }
    if(request->hasParam("valeurDelayOF", true))
    {
      String message;
      message = request->getParam("valeurDelayOF", true)->value();
      valeurDelayOf = message.toInt();
    
    }


     if(request->hasParam("valeurcoupH", true))
    {
      valeurcoupH = request->getParam("valeurcoupH", true)->value().toInt();
    }
      if(request->hasParam("valeurcoupM", true))
    {
      valeurcoupM = request->getParam("valeurcoupM", true)->value().toInt();
    }
      
      if(request->hasParam("valeurdemH", true))
    {
     valeurdemH = request->getParam("valeurdemH", true)->value().toInt();
    request->send(204);
    
    }
     if(request->hasParam("valeurdemH", true))
    {
     valeurdemM = request->getParam("valeurdemH", true)->value().toInt();
    request->send(204);
    }
      
  });

  server.begin();
  Serial.println("Serveur actif!");
}

void loop()
{
  if(etatrelayVoulu)
  {
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= valeurDelayOn)
    {
      previousMillis = currentMillis;

      etatrelay = !etatrelay;
      digitalWrite(relay, etatrelay);
    }
  }
}
