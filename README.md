# Wifi-RSS-based-location-tracking-robot

This location tracking robot could track and follow your smart phone. The main idea was to track the Wi-Fi received signal strength (RSS) on your smart phone (which is in terms of dBm rates). We all know that the strength of any signal is pretty good while we are near the source of the signal and it fades as we move away from it. Based on this concept of signal attenuation with distance, we can make the robot move in the direction where the signal strength tends to increase and thereby make it follow the signal source. The NodeMCU with an inbuilt ESP8266 Wi-Fi module was used as the microcontroller along with basic components under a price of 500 INR to build this bot that could track the RSS of the Wi-Fi network your smartphone hotspot creates.
