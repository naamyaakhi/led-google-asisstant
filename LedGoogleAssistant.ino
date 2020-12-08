#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "kMclGzRh7tMKOxzphQo77FZfFbUeEfjj";
char ssid[] = "Almira04";
char pass[] = "papamama";
void setup()

{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  
}
void loop()

{
  Blynk.run();
}
