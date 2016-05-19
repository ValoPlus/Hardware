//
// Created by torben on 20.02.16.
//

#ifndef FIRMWARE_PCA9685SINGLECHANNEL_H
#define FIRMWARE_PCA9685SINGLECHANNEL_H

#include "PCA9685Channel.h"
class PCA9685SingleChannel :PCA9685Channel{
private:
    uint8_t pin;
public:
    PCA9685SingleChannel(String& name, uint8_t deviceAddress);

};


#endif //FIRMWARE_PCA9685SINGLECHANNEL_H
