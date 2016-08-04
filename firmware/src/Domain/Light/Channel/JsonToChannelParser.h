//
// Created by torben on 23.05.16.
//

#ifndef FIRMWARE_CHANNELINPUT_H
#define FIRMWARE_CHANNELINPUT_H

#include "Channel.h"
#include "WS2812/WS2812Channel.h"
#include "WS2812/WS2812JsonChannelInput.h"
class JsonToChannelParser {

public:
    Channel* parse(String json){
        StaticJsonBuffer<2000> jsonBuffer;
        JsonObject* root = &jsonBuffer.parseObject(json);

        Channel* channel;
        if((*root)["type"].asString() == "WS2812"){
            WS2812JsonChannelInput input = WS2812JsonChannelInput(root);
            channel = new WS2812Channel(input);
        }

        return channel;
    }


};


#endif //FIRMWARE_CHANNELINPUT_H
