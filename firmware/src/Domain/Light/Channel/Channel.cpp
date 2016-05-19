//
// Created by torben on 18.02.16.
//

#include "Channel.h"


Channel::Channel(String& name) {
    this->name = name;
}

void Channel::setName(String& name) {
    this->name = name;
}

String Channel::getName() {
    return this->name;
}