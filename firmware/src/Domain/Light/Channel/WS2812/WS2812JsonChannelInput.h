//
// Created by torben on 23.05.16.
//

#ifndef FIRMWARE_WS2812JSONCHANNELINPUT_H
#define FIRMWARE_WS2812JSONCHANNELINPUT_H

#include <ArduinoJson.h>
#include <include/ArduinoJson/String.hpp>
#include "WS2812ChannelInput.h"

class WS2812JsonChannelInput : public WS2812ChannelInput{
private:
    JsonObject* root;


public:
    WS2812JsonChannelInput(JsonObject* root){
       this->root = root;
    }

    String getName() const{
        return (*root)["name"].asString();
    }

    uint32_t getId() const {
        return atoi((*root)["typedef"]["channelId"].asString());
    }

    uint32_t getLedCount() const {
        return atoi((*root)["typedef"]["ledCount"].asString());
    }
};


#endif //FIRMWARE_WS2812JSONCHANNELINPUT_H
