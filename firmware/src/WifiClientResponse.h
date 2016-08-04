//
// Created by torben on 18.07.16.
//

#ifndef FIRMWARE_WIFICLIENTREPONSE_H
#define FIRMWARE_WIFICLIENTREPONSE_H


#include <WiFiClient.h>
#include <vector>
#include "RestClientResponse.h"
#include "HttpPayload.h"
#include "HttpHeader.h"

class WifiClientResponse {

private:
    WiFiClient client;

    std::vector<HttpHeader> headers;
    HttpPayload payload;

public:
    void setRestResponse(RestClientResponse response);

    void setClient(WiFiClient client);

    WiFiClient getClient();

    std::vector<HttpHeader> getHeaders();

    HttpPayload getPayload();
};


#endif //FIRMWARE_WIFICLIENTREPONSE_H
