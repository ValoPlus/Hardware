//
// Created by torben on 7/18/16.
//

#include <vector>
#include "WifiClientResponse.h"
#include "HttpHeader.h"
#include "HttpPayload.h"

LinkedList<HttpHeader> WifiClientResponse::getHeaders() {
    return this->headers;
}

HttpPayload WifiClientResponse::getPayload() {
    return this->payload;
}

WiFiClient WifiClientResponse::getClient() {
    return this->client;
}





