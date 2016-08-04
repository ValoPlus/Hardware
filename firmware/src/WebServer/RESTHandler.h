//
// Created by torben on 6/19/16.
//

#ifndef FIRMWARE_RESTHANDLER_H
#define FIRMWARE_RESTHANDLER_H


#include <FS.h>
#include <ESP8266WebServer.h>
#include "WebServer.h"

class RESTHandler{

public:
    RESTHandler(ESP8266WebServer& server) : server(server){
        this->server = server;
    }


protected:
    ESP8266WebServer& server;


    bool isClientIdValid() {
        return true;
    }

    void respondWithJsonFile(String path){
        if(SPIFFS.exists(path)){

            File f = SPIFFS.open(path, "r");
            String jsonString = f.readString();
            f.close();

            Serial.println("Sending " + path + " content: " + jsonString);

            server.send(200, "application/json;charset=UTF-8", jsonString);
        }

        else {
            Serial.println("File " + path +" not found");
        }
    }


    void respondWithJsonObject(JsonObject& content){
        String responseString;
        content.printTo(responseString);
        Serial.println("Sending: " + responseString);
        server.send(200, "application/json;charset=UTF-8" , responseString);
    }
};
#endif //FIRMWARE_RESTHANDLER_H
