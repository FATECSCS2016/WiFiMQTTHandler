/*
	Morse.cpp - Library for flashing Morse code.
	Created by David A. Mellis, November 2, 2007.
	Released into the public domain.
*/

#include "Arduino.h"
#include "WiFiHandler.h"
#include "ESP8266WiFi.h"
#include "PubSubClient.h"

WiFiHandler::WiFiHandler(const char *ssid,const char *password, PubSubClient &client,char *mqttServer, int mqttPort, char *mqttUser, char *mqttPassword)
{
		strlcpy(_ssid, ssid, sizeof(_ssid));
		strlcpy(_password, password, sizeof(_password));

		strlcpy(_mqttUser, mqttUser, sizeof(_mqttUser));
		strlcpy(_mqttPassword, mqttPassword, sizeof(_mqttPassword));

		_client = client;
		_client.setServer(mqttServer, mqttPort);
		_isConnect = false;
}

void WiFiHandler::connect()
{
	WiFi.setAutoReconnect(true);
	WiFi.begin(_ssid, _password);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
	}
	while (!_client.connected()) {
    	_client.connect("ESP8266Client", _mqttUser, _mqttPassword);
	}
}

void WiFiHandler::reconnect(){
	WiFi.reconnect();
}

bool WiFiHandler::isConnected()
{
	return WiFi.isConnected() && _client.connected();
}