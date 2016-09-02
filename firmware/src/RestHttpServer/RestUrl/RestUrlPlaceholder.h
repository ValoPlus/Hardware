//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_URLPLACEHOLDER_H
#define FIRMWARE_URLPLACEHOLDER_H


#include <include/ArduinoJson/String.hpp>
#include "RestUrlElement.h"

class UrlPlaceholder : public RestUrlElement{

public:
    UrlPlaceholder(String placeholderName);
private:
    String placeholderName;

};


#endif //FIRMWARE_URLPLACEHOLDER_H
