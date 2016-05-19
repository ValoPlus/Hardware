//
// Created by torben on 20.02.16.
//

#ifndef FIRMWARE_PCA9685CHANNEL_H
#define FIRMWARE_PCA9685CHANNEL_H

#include "Channel.h"

class PCA9685Channel : Channel{
private:
    uint8_t deviceAddress;

    void setValue(uint8_t pin, uint32_t value);
public:
    PCA9685Channel(String& name, uint8_t deviceAddress);

};


#endif //FIRMWARE_PCA9685CHANNEL_H
