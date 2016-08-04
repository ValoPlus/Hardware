//
// Created by torben on 18.02.16.
//

#ifndef FIRMWARE_WLANSETTINGS_H
#define FIRMWARE_WLANSETTINGS_H

#include <Arduino.h>
#include "JsonWlanSettingsInput.h"


class WlanSettings {
private:
    String ssid;
    String password;


public:

    WlanSettings(){}

    WlanSettings(WlanSettingsInput& input) {
        this->ssid = input.getSsid();
        this->password = input.getPassword();
    }

    WlanSettings(String ssid, String password) {
        this->ssid = ssid;
        this->password = password;
    }

    String getSSID() {
        return this->ssid;
    }

    String getPassword() {
        return this->password;
    }





};


#endif //FIRMWARE_WLANSETTINGS_H
