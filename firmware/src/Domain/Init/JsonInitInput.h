//
// Created by torben on 14.05.16.
//

#ifndef FIRMWARE_JSONINITINPUT_H
#define FIRMWARE_JSONINITINPUT_H

#include "InitInput.h"
#include <ArduinoJson.h>

class JsonInitInput : public InitInput {

public:
    JsonInitInput(String json){

        StaticJsonBuffer<1000> jsonBuffer;
        root = &jsonBuffer.parseObject(json);
    };

    virtual String getClientId() const {
        return (*root)["clientId"].asString();
    }

private:
    JsonObject* root;

};


#endif //FIRMWARE_JSONINITINPUT_H
