//
// Created by torben on 7/18/16.
//

#include "RestHttpServer.h"
#include "HttpHeader.h"
#include "HttpPayload.h"
#include "RestHttpServer/Endpoint/ActualEndpoint.h"
#include <include/ArduinoJson/String.hpp>



void RestHttpServer::begin(){
    server.begin();
}
void RestHttpServer::end(){
    server.stop();
}


void RestHttpServer::handleClientConnection() {
    WiFiClient client = server.available();

    //Todo: read and parse client request (http methode and uri)
    HttpMethod method;
    String uri;

    //Todo: Check if request is valid

    //Todo: Pass uri and httpmethode
    RestClientResponse restResponse = callRestEndpoint(client, uri, method);

    WifiClientResponse wifiResponse = WifiClientResponse();
    wifiResponse.setClient(client);
    wifiResponse.setRestResponse(restResponse);

    //Todo: Answer client
    answerClient(wifiResponse);
}


RestClientResponse RestHttpServer::callRestEndpoint(WiFiClient client, String uri, HttpMethod method){
    //Todo: Extract arguments

    //Todo: Somehow collect respones data

    ActualEndpoint endpoint;
    RestClient restClient;
    restClient.setArguments();
    restClient.setHttpMethode(method);


    return endpoint.handleRestClient(restClient);
    //Todo: Return response data and maybe additional headers (?)
}

void RestHttpServer::answerClient(WifiClientResponse response) {
    WiFiClient client = response.getClient();


    LinkedList<HttpHeader> headers = response.getHeaders();

    for(int i = 0; i < headers.size(); i++)
    {
        HttpHeader header = headers.get(i);
        //Todo: Send header name and content
    }

    HttpPayload payload = response.getPayload();
    //TODO: Send payload

}




