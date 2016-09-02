//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_URLCONSTANTELEMENT_H
#define FIRMWARE_URLCONSTANTELEMENT_H


#include <include/ArduinoJson/String.hpp>
#include "RestUrlElement.h"

class UrlConstantElement : RestUrlElement{

public:
    UrlConstantElement(String constant);
private:
    String constant;

};


#endif //FIRMWARE_URLCONSTANTELEMENT_H
