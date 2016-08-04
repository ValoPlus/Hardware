//
// Created by torben on 23.05.16.
//

#ifndef FIRMWARE_WS2812CHANNEL_H
#define FIRMWARE_WS2812CHANNEL_H

#include "WS2812JsonChannelInput.h"

class WS2812Channel : public Channel{

private:
    uint32_t id;
    uint32_t ledCount;

public:
    WS2812Channel(WS2812JsonChannelInput input) : Channel(input.getName()){
        this->id = input.getId();
        this->ledCount= input.getLedCount();
    }




};


#endif //FIRMWARE_WS2812CHANNEL_H
