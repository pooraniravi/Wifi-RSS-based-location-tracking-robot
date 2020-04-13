//complted program
#include "ESP8266WiFi.h"
int d0 = 16;
int d1 = 5;
int d2 = 4;
int d3 = 0;
int prevrssi = 0;
int rssi = 0;
int i;
int fdelay(5000);
int tdelay(400);
void Forward()
{
  digitalWrite(d0, HIGH); //left motor
  digitalWrite(d1, LOW);
  digitalWrite(d2, HIGH); //right motor
  digitalWrite(d3, LOW);
}
void Reverse()
{
  digitalWrite(d0, LOW);
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
}
void Left()
{
  digitalWrite(d0, LOW);
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, LOW);
}
void Right()
{
  digitalWrite(d0, HIGH);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, HIGH);
}
void Stop()
{
  digitalWrite(d0, LOW);
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
}
void updaterssi()
{
  prevrssi = rssi;
  rssi=0;
  for (int j = 1; j <= 5; j++)
 {
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i)
    {
      if (WiFi.SSID(i) == "wififollower")
      {
        int y = WiFi.RSSI(i);
        rssi+=y;
      }
    }
 }
  rssi=rssi/5;
  Serial.print("average rssi = ");
  Serial.println(rssi);
  
}
void setup()
{
  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  updaterssi();
}
void loop()
{ 
  updaterssi();
  if((rssi>=(-45)) && (rssi<=(-40)))
  {
    Stop();
  }
  else if(prevrssi<rssi)
  {
    Forward();
  delay(fdelay);
  }
  else
  {
      Left();
      delay(tdelay);
      Forward();
      delay(fdelay);
      Stop();
      updaterssi();
      if (prevrssi<rssi)
      {
        Forward();
        delay(fdelay);
        loop();
      }
      else
      {
        Reverse();
        delay(fdelay);
        Right();
        delay(tdelay);
      }
      Right();
      delay(tdelay);
      Forward();
      delay(fdelay);
      Stop();
      updaterssi();
      if (prevrssi<rssi)
      {
        Forward();
        delay(fdelay);
        loop();
      }
      else
      {
        Reverse();
        delay(fdelay);
        Left();
        delay(tdelay);
      }
      Reverse();
      delay(fdelay);
      Stop();
      updaterssi();
      if (prevrssi<rssi)
      {
        Reverse();
        delay(fdelay);
      }
      else
        Stop();
  }
}


