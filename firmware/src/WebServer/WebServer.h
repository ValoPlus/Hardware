//
// Created by torben on 12.02.16.
//
#ifndef WEBSERVER2_H
#define WEBSERVER2_H


#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include "InitHandler.h"


class WebServer {



public:

    WebServer(){

    }

    void init() {

        if (mdns.begin("esp8266", WiFi.localIP())) {
            Serial.println("MDNS responder started");
        }

        InitHandler initHandler(*server);
       // SettingsHandler settingsHandler(&server);
        //ChannelHandler channelHandler(&server);

        getServer().on("/", std::bind(&WebServer::handleRoot, this));
        getServer().onNotFound(std::bind(&WebServer::handleNotFound, this));

        getServer().begin();
        Serial.println("HTTP server started");

    }

    ESP8266WebServer& getServer(){
        return *server;
    }

    void handleClient(){
        getServer().handleClient();
    }


private:
    MDNSResponder mdns;
    ESP8266WebServer* server = new ESP8266WebServer(80);



    void handleRoot() {
        getServer().send(200, "text/plain", "Welcome to this Valo+ device :) \n See https://valoplus.de/doku for the documentation of the api.");
    }

    void handleNotFound(){

        String methodeName = "";
        switch (getServer().method()){
            case HTTP_ANY: methodeName = "ANY";
            case HTTP_GET: methodeName = "GET";
            case HTTP_POST: methodeName = "POST";
            case HTTP_PUT: methodeName = "PUT";
            case HTTP_PATCH: methodeName = "PATCH";
            case HTTP_DELETE: methodeName = "DELETE";
            case HTTP_OPTIONS: methodeName = "OPTIONS";
            default: methodeName = "unknown";

        }
        String text = "REST endpoint \"" + getServer().uri() + "\" for methode \"" + methodeName + "\" not found.";
        Serial.println(text);
        getServer().send(404, "text/plain", text);
    }

};

#endif