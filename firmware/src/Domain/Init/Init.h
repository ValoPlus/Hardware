//
// Created by torben on 14.05.16.
//

#ifndef FIRMWARE_INIT_H
#define FIRMWARE_INIT_H

#include <Arduino.h>
#include "InitInput.h"

class Init {

private:
    String clientId;

public:
    Init(InitInput& input){
        this->clientId = input.getClientId();
    }


};


#endif //FIRMWARE_INIT_H
