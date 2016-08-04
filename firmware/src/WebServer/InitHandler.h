//
// Created by torben on 6/19/16.
//

#ifndef FIRMWARE_INITHANDLER_H
#define FIRMWARE_INITHANDLER_H


#include "../Domain/Init/JsonInitInput.h"
#include "../Domain/Init/Init.h"

#include "RESTHandler.h"
#include "WebServer.h"


class InitHandler : public RESTHandler{

public:

    InitHandler(ESP8266WebServer& server) : RESTHandler(server){

        setupEndpoints();
    }

    void setupEndpoints(){
        server.on("/api/init", HTTP_OPTIONS, std::bind(&InitHandler::handleOptionsInit, this));
        server.on("/api/init", HTTP_POST, std::bind(&InitHandler::handlePostInit, this));
    }

    void handleOptionsInit(){
        Serial.println("Options");
        server.send(200, "text/plain", "ok");

    }
    void handlePostInit() {
        Serial.println("Post");

        String jsonString = server.arg(0);
        Serial.println("r: " + jsonString);
        //Parse the recieved json data
        JsonInitInput initInput = JsonInitInput(jsonString);
        Init init = Init(initInput);


        StaticJsonBuffer<1000> jsonBuffer;
        JsonObject& response = jsonBuffer.createObject();
        response["controllerType"] = "VP-Dev1";
        response["availableChannel"] = 2;
        response["controllerAlias"] = "";
        response["configured"] =  true;

        respondWithJsonObject(response);
        Serial.println("init");

    }

};
#endif //FIRMWARE_INITHANDLER_H
