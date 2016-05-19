//
// Created by torben on 03.04.16.
//

#ifndef FIRMWARE_JSONSETTINGSINPUT_H
#define FIRMWARE_JSONSETTINGSINPUT_H


#include "SettingsInput.h"
#include <ArduinoJson.h>
#include "Wlan/WlanSettings.h"
#include "Wlan/JsonWlanSettingsInput.h"

class JsonSettingsInput : public SettingsInput {
private:
    JsonObject* root;


public:
    JsonSettingsInput(String json){

        Serial.print("JsonSettingsInput in: " + json);
        StaticJsonBuffer<2000> jsonBuffer;
        root = &jsonBuffer.parseObject(json);
    }

    String getControllerAlias() const{
        return (*root)["controllerAlias"].asString();
    }

    WlanSettings getWlanSettings() const{
        Serial.print("wlan in: ");

        String wlan = (*root)["wlan"]["ssid"].asString();

        Serial.println(wlan);

        //JsonWlanSettingsInput input = JsonWlanSettingsInput(wlan);
        Serial.println("wlan c");
        return WlanSettings((*root)["wlan"]["ssid"].asString(), (*root)["wlan"]["pass"].asString());
    }


};


#endif //FIRMWARE_JSONSETTINGSINPUT_H
