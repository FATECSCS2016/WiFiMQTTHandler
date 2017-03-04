/*
	Morse.h - Library for flashing Morse code.
	Created by David A. Mellis, November 2, 2007.
	Released into the public domain.
*/
#ifndef WiFiHandler_h
#define WiFiHandler_h

#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "PubSubClient.h"

class WiFiHandler
{
	public:
		WiFiHandler(const char *ssid,const char *password, PubSubClient &client,char *mqttServer, int qttPort, char *mqttUser, char *mqttPassword);
		bool isConnected();
		void connect();
		void reconnect();
	private:
		char _ssid[32];
		char _password[32];
		bool _isConnect;
		PubSubClient _client;
		char _mqttUser[32];
		char _mqttPassword[32];
};

#endif