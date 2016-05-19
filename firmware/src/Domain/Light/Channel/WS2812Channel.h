//
// Created by torben on 18.02.16.
//

#ifndef FIRMWARE_WS2812CHANNEL_H
#define FIRMWARE_WS2812CHANNEL_H

#include <NeoPixelBus.h>

#include "Channel.h"
#include "../LED/ColorLed.h"
#include <vector>
class WS2812Channel : Channel{

private:
    std::vector<ColorLed> leds;


    void update();

public:
    WS2812Channel(String& name, uint8_t pin, uint16_t ledCount);
    uint32_t getLedCount();

    void addLed(ColorLed& led);

    ColorLed getLed(uint32_t position);

    void setColorForAll(Color color);


};


#endif //FIRMWARE_WS2812CHANNEL_H
