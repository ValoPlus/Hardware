//
// Created by torben on 03.04.16.
//

#ifndef FIRMWARE_SETTINGS_H
#define FIRMWARE_SETTINGS_H



#include <Arduino.h>
#include "Wlan/WlanSettings.h"
#include "SettingsInput.h"

class Settings {

    String controllerAlias;
    WlanSettings wlanSettings;


public:
    Settings(SettingsInput& input) {
        Serial.println("wlan");
        wlanSettings = input.getWlanSettings();

        Serial.println("alias");
        controllerAlias = input.getControllerAlias();
    }


    const WlanSettings &getWlanSettings() const {
        return wlanSettings;
    }

    const String &getControllerAlias() const {
        return controllerAlias;
    }
};


#endif //FIRMWARE_SETTINGS_H
