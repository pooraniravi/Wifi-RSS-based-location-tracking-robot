//to take average of rssi values and print it using another for loop
#include "ESP8266WiFi.h"
int rssi = 0;
int i;
int y=0;
void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}
void loop()
{
 
  for (int j = 1; j <= 5; j++)
  {
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; i++)
    {
      if ((WiFi.SSID(i)) == "wififollower")
      {

        int y = WiFi.RSSI(i);
        rssi=rssi+y;
        Serial.print(WiFi.SSID(i)); 
        Serial.print(y); 
      }
    }
   
  }
   rssi=rssi/5;
   Serial.print("average");
   Serial.println(rssi);
   rssi=0;
}
