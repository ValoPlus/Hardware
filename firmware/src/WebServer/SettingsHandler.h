//
// Created by torben on 6/19/16.
//

#ifndef FIRMWARE_SETTINGSHANDLER_H
#define FIRMWARE_SETTINGSHANDLER_H

#include "Arduino.h"
#include "../Domain/Settings/JsonSettingsInput.h"
#include "../Domain/Settings/Settings.h"
#include "RESTHandler.h"

#include <ESP8266WebServer.h>
#include <FS.h>

class SettingsHandler : public RESTHandler {
/*
public:

    SettingsHandler(ESP8266WebServer* server):RESTHandler(server){

        server->on("/api/settings/alias,", HTTP_POST, std::bind(&SettingsHandler::handlePostAlias, this));

        server->on("/api/settings/wlan", HTTP_GET, std::bind(&SettingsHandler::handleGetWlan, this));
        server->on("/api/settings/wlan", HTTP_POST, std::bind(&SettingsHandler::handlePostWlan, this));
    }


    void handlePostAlias() {
        if(isClientIdValid()) {

            if (server->method() == HTTP_GET) {
                respondWithJsonFile("/settings.json");
            }

            else if (server->method() == HTTP_POST) {
                String jsonString = server->arg(0);

                JsonSettingsInput settingsInput = JsonSettingsInput(jsonString);
                Settings settings = Settings(settingsInput);

                if (SPIFFS.exists("/settings.json"))
                    SPIFFS.remove("/settings.json");

                File f = SPIFFS.open("/settings.json", "w");
                f.println(jsonString);
                f.close();

                server->send(200, "text/plain", "OK");
                Serial.println("done");
            }
        }
    }

    void handleGetWlan() {
        if(isClientIdValid()) {
            respondWithJsonFile("/wlan.json");
        }
    }

    void handlePostWlan() {
        if(isClientIdValid()) {
                String jsonString = server->arg(0);

                JsonWlanSettingsInput settingsInput = JsonWlanSettingsInput(jsonString);
                Serial.println("input done");
                WlanSettings settings = WlanSettings(settingsInput);


                if (SPIFFS.exists("/wlan.json"))
                    SPIFFS.remove("/wlan.json");

                File f = SPIFFS.open("/wlan.json", "w");
                f.println(jsonString);
                f.close();

            server->send(200, "text/plain", "OK");

            }
    }
*/
public:
    SettingsHandler(WebServer &server) : RESTHandler(server) { }
};


#endif //FIRMWARE_SETTINGSHANDLER_H
