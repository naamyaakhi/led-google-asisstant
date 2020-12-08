#include <UbidotsMicroESP8266.h>

#include  "DHT.h"
#include "UbidotsMicroESP8266.h"
#define DHTPIN 4 
#define TOKEN "BBFF-4mj0UtufbEtRX610XdzBSPnoGu4WWS" //token dari ubidots
#define ssid "Almira04"
#define psswd "papamama"
DHT dht (DHTPIN , DHT11);
Ubidots client(TOKEN);
unsigned long last =0;

void setup(){
  Serial.begin(9600);

  dht.begin();

  delay(20);

  client.wifiConnection(ssid,psswd);
  
}

void loop(){
  if (milis()-last>1000){
    float hum = dht.readHumitidy(); //tipe data float untu menampung data kelembapan

    float temp = dht.readTemperatur(); //tipe data float untuk menampung data suhu

    last=milis();

    client.add("kelembapan",hum);

    client.add("Temp",temp);

    client.sendAll(true);
  }
}
