#include<Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include<PubSubClient.h>
#include "DHT.h"

#define DHTTYPE DHT11

WiFiClient g_client;
PubSubClient client(g_client);
const char *ssid="Samsung";
const char *password="0123456789";

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "iot.iandwe.in";
//WiFiServer server(80);
int LED_Pin=14;
int LED_Pin2=12;
const int DHTPin = 5 ;// DHT SENSOR - GPIO 5 =D1

//Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);

//Timers auxiliar variables
long now = millis();
long lastMeasure = 0;

void setup_wifi() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);

  pinMode(LED_Pin,OUTPUT);
  digitalWrite(LED_Pin, LOW);

  pinMode(LED_Pin2,OUTPUT);
  digitalWrite(LED_Pin2, LOW);

  Serial.print("Connecting . . . . . . .");
  while (WiFi.status() !=WL_CONNECTED){
    delay(1500);
    Serial.print("*");
  }
  Serial.print("\nConnected to ");
  Serial.println(ssid);
  Serial.print("Local IP Address: ");
  Serial.print("http://");
  
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Serial.println();

}

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  String messageTempfan;
  String messageTemp_all;
  String message_autofan;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTempfan += (char)message[i];
  }
    Serial.println();

    for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp_all += (char)message[i];
  }
    Serial.println();

    for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    message_autofan += (char)message[i];
  }
    Serial.println();

if (topic=="gourab_room/lamp")
  {
  Serial.print("Changing Gourab's Room Lamp to ");
    if(messageTempfan == "on"){
      digitalWrite(LED_Pin, HIGH);
      Serial.print("ON.");
    }
    else if(messageTemp == "off"){
      digitalWrite(LED_Pin, LOW);
      Serial.print("OFF.");
    }
  }
      Serial.println();
     if(topic=="gourab_room/fan"){
       Serial.print("Changing Gourab's Room Fan to ");
      if(messageTempfan = "on"){
        digitalWrite(LED_Pin2, HIGH);
        Serial.print("On");
      }
      else if(messageTempfan=="off"){
        digitalWrite(LED_Pin2, LOW);
        Serial.print("OFF");
      }
     }
      Serial.println();
      if(topic=="gourab_room/turn_on_both"){
        if(messageTemp_all=="on"){
            digitalWrite(LED_Pin,HIGH);
            digitalWrite(LED_Pin2,HIGH);
            Serial.print("Turning ON Everything...");
          }
          else if(messageTemp_all=="off"){
            digitalWrite(LED_Pin,LOW);
            digitalWrite(LED_Pin2,LOW);
            Serial.print("Turning OFF Everything...");
          }
      }
      Serial.println();
      if(topic=="gourab_room/automate_fan"){
        if(message_autofan=="on"){
          int t = dht.readTemperature();  
          if(t>28){
            digitalWrite(LED_Pin2,HIGH);
            Serial.println("As temperature is high, I switched on the fan.");
          }
          else if(message_autofan=="off"){
            digitalWrite(LED_Pin2,LOW);
            Serial.println("As temperature is low, I switched off the fan.");
          }
      }
      }
      Serial.println();
 }

void reconnect(){
  //Loop until we are reconnected...
  while(!client.connected()){
    Serial.print("Attempting MQTT connection..."); //Attempting to connect 
  
  if(client.connect("g_client")){
    Serial.println("Connected.");
    client.subscribe("gourab_room/lamp");
    client.subscribe("gourab_room/fan");
    client.subscribe("gourab_room/turn_on_both");
    client.subscribe("gourab_room/automate_fan");
  }
  else{
     Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
  }
}
}
void setup()
{
  pinMode(LED_Pin, OUTPUT);
  pinMode(LED_Pin2,OUTPUT);
  dht.begin();
  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  now = millis();
  // Publishes new temperature and humidity every 2 seconds
  if (now - lastMeasure > 2000) {
    lastMeasure = now;
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    // Computes temperature values in Celsius
    float hic = dht.computeHeatIndex(t, h, false);
    static char temperatureTemp[7];
    dtostrf(hic, 6, 2, temperatureTemp);
    
    //Uncomment to compute temperature values in Fahrenheit 
    //float hif = dht.computeHeatIndex(f, h);
    //static char temperatureTemp[7];
    //dtostrf(hic, 6, 2, temperatureTemp);
    
    static char humidityTemp[7];
    dtostrf(h, 6, 2, humidityTemp);

    //Publishes Temperature and Humidity values
    client.publish("gourab_room/temperature", temperatureTemp);
    client.publish("gourab_room/humidity", humidityTemp);
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t Heat index: ");
    Serial.print(hic);
    Serial.println(" *C ");
    // Serial.print(hif);
    // Serial.println(" *F");
  }
}
