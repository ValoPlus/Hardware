//
// Created by torben on 18.02.16.
//


#include "WS2812Channel.h"

#include <NeoPixelBus.h>
#include "../LED/ColorLed.h"

WS2812Channel::WS2812Channel(String& name, uint8_t pin, uint16_t ledCount) : Channel(name){


    for(int i = 0; i < ledCount; i++){
        ColorLed led = ColorLed();
        leds.push_back(led);
    }


    this->update();


}

void WS2812Channel::update() {

    for(int i = 0; i < leds.size(); i++){
        ColorLed led = leds.at(i);
        RgbColor color = RgbColor(led.getColor().getR(), led.getColor().getB(), led.getColor().getB());

    }


}