//
// Created by torben on 20.02.16.
//

#ifndef FIRMWARE_COLORLED_H
#define FIRMWARE_COLORLED_H


#include "../Color/Color.h"
#include "LED.h"
class ColorLed : LED {
private:
    Color color;
public:
    ColorLed();

    void setColor(Color& color);
    Color getColor();
};


#endif //FIRMWARE_COLORLED_H
