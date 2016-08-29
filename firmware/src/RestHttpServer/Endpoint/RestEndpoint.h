//
// Created by torben on 7/18/16.
//

#ifndef FIRMWARE_RESTENDPOINT_H
#define FIRMWARE_RESTENDPOINT_H


#include <c_types.h>
#include "RestHttpServer/RestClient.h"
#include "RestHttpServer/RestClientResponse.h"

class RestEndpoint {

public:
    virtual RestClientResponse handleRestClient(RestClient client) = 0;
};





#endif //FIRMWARE_RESTENDPOINT_H
