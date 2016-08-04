//
// Created by torben on 7/18/16.
//

#ifndef FIRMWARE_RESTCLIENT_H
#define FIRMWARE_RESTCLIENT_H


#include "HttpMethod.h"

class RestClient {

public:
    void setArguments();

    void setHttpMethode(HttpMethod method);
};


#endif //FIRMWARE_RESTCLIENT_H
