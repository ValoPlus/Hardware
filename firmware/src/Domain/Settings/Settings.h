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



public:
    Settings(SettingsInput& input) {

        Serial.println("alias");
        controllerAlias = input.getControllerAlias();
    }



    const String &getControllerAlias() const {
        return controllerAlias;
    }
};


#endif //FIRMWARE_SETTINGS_H
