//
// Created by torben on 12.02.16.
//

#include "WebServer.h"
#include "../Domain/Settings/JsonSettingsInput.h"
#include "../Domain/Settings/Settings.h"
#include "../Domain/Init/JsonInitInput.h"
#include "../Domain/Init/Init.h"


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <ArduinoJson.h>



MDNSResponder mdns;
ESP8266WebServer server(80);


void respondWithJsonFile(String path){
    if(SPIFFS.exists(path)){

    File f = SPIFFS.open(path, "r");
    String jsonString = f.readString();
    f.close();

    Serial.println("Sending " + path + " content: " + jsonString);

    server.send(200, "application/json;charset=UTF-8", jsonString);
    }

    else
    {
        Serial.println("File " + path +" not found");
    }
}


void respondWithJsonObject(JsonObject& content){
    String responseString;
    content.printTo(responseString);
    Serial.println("Sending: " + responseString);
    server.send(200, "application/json;charset=UTF-8" , responseString);
}



void WebServer::init() {
    if (mdns.begin("esp8266", WiFi.localIP())) {
        Serial.println("MDNS responder started");
    }

    server.on("/", std::bind(&WebServer::handleRoot, this));
    server.on("/api/init", std::bind(&WebServer::handleInit, this));
    server.on("/api/channel", std::bind(&WebServer::handleChannel, this));

    server.on("/api/status", std::bind(&WebServer::handleStatus, this));
    server.on("/api/settings", std::bind(&WebServer::handleSettings, this));
    server.on("/api/settings/wlan", std::bind(&WebServer::handleSettingsWlan, this));

    server.onNotFound(std::bind(&WebServer::handleNotFound, this));

    server.begin();
    Serial.println("HTTP server started");

}

void WebServer::handleClient(){
    server.handleClient();
}

void WebServer::handleRoot() {
    server.send(200, "text/plain", "Welcome to this Valo+ controller :) \n See <link> for the documentation of the api.");
}

void WebServer::handleStatus() {
    if(isClientIdValid()) {
        server.send(200, "text/plain", "status");
    }
}

void WebServer::handleInit() {
    if(server.method() == HTTP_POST)
    {
        String jsonString = server.arg(0);
        Serial.println("Recieved: " + jsonString);

        //Parse the recieved json data
        JsonInitInput initInput = JsonInitInput(jsonString);
        Init init = Init(initInput);



        StaticJsonBuffer<1000> jsonBuffer;
        JsonObject& response = jsonBuffer.createObject();
        response["controllerType"] = "VP-Dev1";
        response["availableChannel"] = 2;

        respondWithJsonObject(response);

    }
}

void WebServer::handleChannel() {
    if(isClientIdValid()) {
        if (server.method() == HTTP_GET) {
            String clientId = server.arg(0);

            respondWithJsonFile("/channel.json");

        }
    }
}

void WebServer::handleSettings() {
    if(isClientIdValid()) {

        if (server.method() == HTTP_GET) {
            respondWithJsonFile("/settings.json");
        }

        else if (server.method() == HTTP_POST) {
            String jsonString = server.arg(0);
            Serial.println("Recieved: " + jsonString);

            Serial.println("parsing");
            //Parse the recieved json data
            JsonSettingsInput settingsInput = JsonSettingsInput(jsonString);
            Serial.println("input done");
            Settings settings = Settings(settingsInput);

            Serial.println("check/delete old settings");
            if (SPIFFS.exists("/settings.json"))
                SPIFFS.remove("/settings.json");


            Serial.println("save new settings");
            //Save it
            File f = SPIFFS.open("/settings.json", "w");
            f.println(jsonString);
            f.close();

            Serial.println("responde");
            server.send(200, "text/plain", "OK");
            Serial.println("done");
        }
    }
}


void WebServer::handleSettingsWlan() {
    if(isClientIdValid()) {

        if (server.method() == HTTP_GET) {
            respondWithJsonFile("/wlan.json");
        }

        else if (server.method() == HTTP_POST) {
            String jsonString = server.arg(0);
            Serial.println("Recieved: " + jsonString);

            Serial.println("parsing");
            //Parse the recieved json data
            JsonWlanSettingsInput settingsInput = JsonWlanSettingsInput(jsonString);
            Serial.println("input done");
            WlanSettings settings = WlanSettings(settingsInput);

            Serial.println("check/delete old settings");
            if (SPIFFS.exists("/wlan.json"))
                SPIFFS.remove("/wlan.json");


            Serial.println("save new settings");
            //Save it
            File f = SPIFFS.open("/wlan.json", "w");
            f.println(jsonString);
            f.close();

            Serial.println("responde");
            server.send(200, "text/plain", "OK");
            Serial.println("done");
        }
    }
}
void WebServer::handleNotFound(){
    String text = "REST endpoint \"" + server.uri() + "\" not found.\"";
    Serial.println(text);
    server.send(404, "text/plain", text+6);
}


bool WebServer::isClientIdValid() {
    return true;
}

