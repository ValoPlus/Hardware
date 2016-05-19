//
// Created by torben on 18.02.16.
//

#ifndef FIRMWARE_COLOR_H
#define FIRMWARE_COLOR_H

#include <Arduino.h>

class Color {
private:
    uint32_t r;
    uint32_t g;
    uint32_t b;

public:
    Color();
    Color(uint32_t r, uint32_t g, uint32_t b);

    uint32_t getR();
    uint32_t getG();
    uint32_t getB();

    void setR(uint32_t r);
    void setG(uint32_t g);
    void setB(uint32_t b);

    void setColor(uint32_t r, uint32_t g, uint32_t b);

};


#endif //FIRMWARE_COLOR_H
