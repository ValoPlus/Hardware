//
// Created by torben on 03.04.16.
//

#ifndef FIRMWARE_WLANSETTINGSINPUT_H
#define FIRMWARE_WLANSETTINGSINPUT_H



#include <Arduino.h>

class WlanSettingsInput {

public:
    virtual String getSsid() const = 0;
    virtual String getPassword() const = 0;


};
#endif //FIRMWARE_WLANSETTINGSINPUT_H