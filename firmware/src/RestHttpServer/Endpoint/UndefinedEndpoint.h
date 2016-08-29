//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_UNDEFINEDENDPOINT_H
#define FIRMWARE_UNDEFINEDENDPOINT_H


#include "RestEndpoint.h"
#include "RestHttpServer/RestClientResponse.h"

class UndefinedEndpoint : public RestEndpoint {

public:
    static UndefinedEndpoint& getInstance();
    RestClientResponse handleRestClient(RestClient client);


private:
    UndefinedEndpoint(){};
    static UndefinedEndpoint* instance;

};



#endif //FIRMWARE_UNDEFINEDENDPOINT_H
