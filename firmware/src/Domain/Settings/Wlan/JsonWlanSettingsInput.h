//
// Created by torben on 03.04.16.
//

#ifndef FIRMWARE_JSONWLANSETTINGSINPUT_H
#define FIRMWARE_JSONWLANSETTINGSINPUT_H

#include "WlanSettingsInput.h"
#include <ArduinoJson.h>

class JsonWlanSettingsInput : public WlanSettingsInput{

private:
    JsonObject* root;

public:
    JsonWlanSettingsInput(String json){
        Serial.print("JsonWlanSettingsInput in: " + json);
        StaticJsonBuffer<2000> jsonBuffer;
        root = &jsonBuffer.parseObject(json);
    }

    String getSsid() const{
        return (*root)["ssid"].asString();
    }
    String getPassword()const{
        return (*root)["pass"].asString();
    }



};


#endif //FIRMWARE_JSONWLANSETTINGSINPUT_H
