//
// Created by torben on 6/19/16.
//

#ifndef FIRMWARE_CHANNELHANDLER_H
#define FIRMWARE_CHANNELHANDLER_H


#include "RESTHandler.h"
#include "../Domain/Light/Channel/Channel.h"
#include "../Domain/Light/Channel/JsonToChannelParser.h"
/*
class ChannelHandler : public RESTHandler{

public:
    ChannelHandler(ESP8266WebServer* server) : RESTHandler(server){
        server->on("/api/channel", HTTP_GET, std::bind(&ChannelHandler::handleGetChannel, this));
        server->on("/api/channel", HTTP_POST, std::bind(&ChannelHandler::handlePostChannel, this));
        server->on("/api/channel", HTTP_PUT, std::bind(&ChannelHandler::handlePutChannel, this));
        server->on("/api/channel", HTTP_DELETE, std::bind(&ChannelHandler::handleDeleteChannel, this));

    }

public:

    void handleGetChannel(){
        if(isClientIdValid()) {
            respondWithJsonFile("/channel.json");
        }
    }

    void handlePostChannel(){
        if(isClientIdValid()) {
            JsonToChannelParser parser = JsonToChannelParser();
            Channel* c = parser.parse(server->arg(0));
            Serial.println(c->getName());
        }
    }

    void handlePutChannel(){
    }

    void handleDeleteChannel(){
    }

};

*/

#endif //FIRMWARE_CHANNELHANDLER_H
