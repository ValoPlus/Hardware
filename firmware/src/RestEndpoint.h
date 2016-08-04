//
// Created by torben on 7/18/16.
//

#ifndef FIRMWARE_RESTENDPOINT_H
#define FIRMWARE_RESTENDPOINT_H


#include <c_types.h>
#include "RestClient.h"
#include "RestClientResponse.h"

class RestEndpoint {

public:
    RestClientResponse handleRestClient(RestClient client);
};

RestClientResponse handleRestClient(RestClient client) {
    return RestClientResponse();
}


#endif //FIRMWARE_RESTENDPOINT_H
