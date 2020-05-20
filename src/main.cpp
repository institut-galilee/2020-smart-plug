#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <ezTime.h>
#include <WiFi.h>
const char *ssid = "Geny";
const char *password = "lancer123";

//Variables en lien avec la gestion du temps
int currentTime[5] = {0, 0, 0, 0, 0}; //Heure = 0, Minute = 1, Jour = 2, Mois = 3, Année = 4
Timezone myTZ;


const int relay = 2;
const int capteurElectricite = 34;

int valeurDelayOn;
bool etatrelay = 0;
int valeurDelayOf;
int valeurdemM;
int valeurdemH;
int valeurcoupM;
int valeurcoupH;


AsyncWebServer server(80);
void getCurrentTime()
{ 
  currentTime[0] = myTZ.hour();
  currentTime[1] = myTZ.minute(); 
  currentTime[2] = myTZ.day();
  currentTime[3] = myTZ.month();
  currentTime[4] = myTZ.year();
}

int WattTrans(){
  int i;
  int pot=0;
  int cons=0;
for(i=0;i<9000;i++){
    for(int j=0;j<1000;j++){
      cons = cons + analogRead(capteurElectricite);
    }  
  cons=cons/1000;
  pot= pot+cons;
  }
  return pot/9000;

}

void timerControl(){
  bool etatT=1;
  long int my_timer = millis();
  int heur =myTZ.hour();
  int min =myTZ.minute();

  //delay(1000);
  digitalWrite(relay, HIGH);
  //delay(1000);
  while( heur != valeurcoupH || min != valeurcoupM)
  {
    Serial.print("while");
    Serial.print("\n");
    if(valeurDelayOf != 0 && valeurDelayOn !=0 ){
      if(etatT)
      {
        if ((long)millis() - my_timer > valeurDelayOn*6000 ) {
        my_timer = millis();   
         etatT=!etatT;
        digitalWrite(relay, LOW);
        }  

      }

      else
      {
       if ((long)millis() - my_timer > valeurDelayOf*6000 ) {
        my_timer = millis();   
        etatT=!etatT;
        digitalWrite(relay, HIGH);
        }

      }
    }
    
    heur = myTZ.hour();;
    min = myTZ.minute();
  }
  digitalWrite(relay, LOW);
  
}


void setup()
{
  
  //----------------------------------------------------Serial
  Serial.begin(115200);
  Serial.println("\n");

  //----------------------------------------------------GPIO
  pinMode(relay, OUTPUT);
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
    delay(10);
  }

  Serial.println("\n");
  Serial.println("Connexion etablie!");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());

  waitForSync();
  
  myTZ.setLocation(F("fr"));


  
  

  //----------------------------------------------------SERVER
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", "text/html");
  });

  server.on("/w3.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/w3.css", "text/css");
  });

  server.on("/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/script.js", "text/javascript");
  });

  server.on("/jquery-3.5.1.min.js", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/jquery-3.5.1.min.js", "text/javascript");
  });

  server.on("/lireElectricite", HTTP_GET, [](AsyncWebServerRequest *request) {
    int val = WattTrans();
    String electr = String(val);
    request->send(200, "text/plain", electr);
  });

  server.on("/on", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(relay, HIGH);
    request->send(204);
  });

  server.on("/off", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(relay, LOW);
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
      String message;
      message = request->getParam("valeurcoupH", true)->value();
      valeurcoupH= message.toInt();
    }
    if(request->hasParam("valeurcoupM", true))
    {
      String message;
      message = request->getParam("valeurcoupM", true)->value();
      valeurcoupM = message.toInt();
    } 
    if(request->hasParam("valeurdemH", true))
    {
      String message;
      message= request->getParam("valeurdemH", true)->value();
      valeurdemH = message.toInt();
        Serial.println(valeurdemH);
    }
    if(request->hasParam("valeurdemM", true))
    {
      String message;
      message = request->getParam("valeurdemM", true)->value();
      valeurdemM = message.toInt();
      Serial.println(valeurdemM);
    }

    request->send(204);
      
  });
  
  server.begin();
  Serial.println("Serveur actif!");
  Serial.println(myTZ.dateTime());



  //setEvent( timerControl , valeurdemH,valeurdemM, 0, myTZ.day(), myTZ.month(), myTZ.year());
  

}

void loop()
{
    if(valeurdemH == myTZ.hour() && valeurdemM==myTZ.minute()&&myTZ.second()==0 && myTZ.day()&&myTZ.month()&&myTZ.year() ){

    timerControl ();
  }
  //events();
}
