//
// Created by torben on 03.04.16.
//

#ifndef FIRMWARE_SETTINGSINPUT_H
#define FIRMWARE_SETTINGSINPUT_H


#include "Wlan/WlanSettings.h"

class SettingsInput {

public:
    virtual String getControllerAlias() const = 0;
    virtual WlanSettings getWlanSettings() const = 0;


};


#endif //FIRMWARE_SETTINGSINPUT_H
