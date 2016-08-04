//
// Created by torben on 23.05.16.
//

#ifndef FIRMWARE_WS2812CHANNELINPUT_H
#define FIRMWARE_WS2812CHANNELINPUT_H


#include <stdint.h>

class WS2812ChannelInput {
public:
    virtual String getName() const = 0;
    virtual uint32_t getId() const = 0;
    virtual uint32_t getLedCount() const = 0;

};


#endif //FIRMWARE_WS2812CHANNELINPUT_H
