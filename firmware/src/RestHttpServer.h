//
// Created by torben on 7/17/16.
//

#ifndef FIRMWARE_HTTPSERVER_H
#define FIRMWARE_HTTPSERVER_H

#include <WiFiClient.h>
#include <map>
#include "WiFiServer.h"
#include "RestEndpoint.h"
#include "RestClient.h"
#include "RestClientResponse.h"
#include "WifiClientResponse.h"
#include "HttpMethod.h"
/**
 *
 * Todo: Https Support
 */
class RestHttpServer {

private:
    WiFiServer server;

    std::map<String, RestEndpoint> restEndpoints;

public:

    RestHttpServer(IPAddress address, int port) : server(address, port){
    }
    RestHttpServer(int port) : server(port){
    }


    /**
     * Adds an RestEndpoint with a certain url. A RestEndpoint may only be added once to a RestHttpServer instance.
     */
    void addEndpoint(String url, RestEndpoint endpoint);

    void removeEndpoint(RestEndpoint endpoint);

    void begin();

    void stop();

    void handleClientConnection();

    void answerClient(WifiClientResponse response);

    RestClientResponse callRestEndpoint(WiFiClient client, String uri, HttpMethod method);


};


#endif //FIRMWARE_HTTPSERVER_H


