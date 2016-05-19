//
// Created by torben on 18.02.16.
//

#ifndef FIRMWARE_CHANNEL_H
#define FIRMWARE_CHANNEL_H

#include <Arduino.h>

class Channel {

private:
    String name;

public:
    Channel(String& name);
    String getName();
    void setName(String& name);

};


#endif //FIRMWARE_CHANNEL_H
