//
// Created by torben on 14.05.16.
//

#ifndef FIRMWARE_INITINPUT_H
#define FIRMWARE_INITINPUT_H

#include <Arduino.h>
class InitInput {

public:
    virtual String getClientId() const = 0;
};


#endif //FIRMWARE_INITINPUT_H
