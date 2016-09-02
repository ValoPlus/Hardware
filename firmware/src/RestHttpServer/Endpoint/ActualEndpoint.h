//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_ACTUALENDPOINT_H
#define FIRMWARE_ACTUALENDPOINT_H


#include "RestEndpoint.h"

class ActualEndpoint : public RestEndpoint{

public:
    virtual RestClientResponse handleRestClient(RestClient client) {
        return RestClientResponse();
    }
};


#endif //FIRMWARE_ACTUALENDPOINT_H
