//second version of completed program
#include "ESP8266WiFi.h"
int d0 = 16;
int d1 = 5;
int d2 = 4;
int d3 = 0;
int prevrssi = 0;
int rssi = 0;
int i;
char y=0;
//char array_rssi[10];//unsigned int 8 bit array declartion
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
    int n = WiFi.scanNetworks();
    char index=0;
    while(index<10)
    {
      for (int i = 0; i < n; ++i)
      {
      if (WiFi.SSID(i) == "wififollower")
      {
         y = WiFi.RSSI(i);
         rssi=rssi+y;
         index=index+1;
      }
      }
    }
  rssi=rssi/10;
  prevrssi=rssi;
  rssi=0;
  index=0;
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
  if ((rssi>=(-60)) && (rssi<= (-40)))
  {
    Stop();
  }
  else if(prevrssi<rssi)
      Forward();
  else
    {
      Left();
      delay(200);
      Forward();
      delay(3000);
      Stop();
      updaterssi();
      if (prevrssi<rssi)
      {
        Forward();
      }
      else
      {
        Reverse();
        delay(3000);
        Right();
        delay(200);
      }
      Right();
      delay(200);
      Forward();
      delay(3000);
      Stop();
      updaterssi();
      if (prevrssi<rssi)
      {
        Forward();
      }
      else
      {
        Reverse();
        delay(3000);
        Left();
        delay(200);
      }
      Reverse();
      delay(3000);
      Stop();
      updaterssi();
      if (prevrssi<rssi)
      {
        Reverse();
      }
      else
        Stop();
    }
}


