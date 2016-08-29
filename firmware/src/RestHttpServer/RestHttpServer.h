//
// Created by torben on 7/17/16.
//

#ifndef FIRMWARE_HTTPSERVER_H
#define FIRMWARE_HTTPSERVER_H

#include <WiFiClient.h>
#include <map>
#include "WiFiServer.h"
#include "Endpoint/RestEndpoint.h"
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



public:

    RestHttpServer(IPAddress address, int port) : server(address, port){
    }

    RestHttpServer(int port) : server(port){
    }




    void begin();

    void end();

    void handleClientConnection();

    void answerClient(WifiClientResponse response);

    RestClientResponse callRestEndpoint(WiFiClient client, String uri, HttpMethod method);


};


#endif //FIRMWARE_HTTPSERVER_H


