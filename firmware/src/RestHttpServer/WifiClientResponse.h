//
// Created by torben on 18.07.16.
//

#ifndef FIRMWARE_WIFICLIENTREPONSE_H
#define FIRMWARE_WIFICLIENTREPONSE_H


#include <WiFiClient.h>
#include <LinkedList.h>
#include "RestClientResponse.h"
#include "HttpPayload.h"
#include "HttpHeader.h"

class WifiClientResponse {

private:
    WiFiClient client;

    LinkedList<HttpHeader> headers;
    HttpPayload payload;

public:
    void setRestResponse(RestClientResponse response);

    void setClient(WiFiClient client);

    WiFiClient getClient();

    LinkedList<HttpHeader> getHeaders();

    HttpPayload getPayload();
};


#endif //FIRMWARE_WIFICLIENTREPONSE_H
