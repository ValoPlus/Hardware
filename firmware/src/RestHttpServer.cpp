//
// Created by torben on 7/18/16.
//

#include "RestHttpServer.h"
#include "HttpHeader.h"
#include "HttpPayload.h"
#include <include/ArduinoJson/String.hpp>
#include <vector>



void RestHttpServer::begin(){
    server.begin();
}
void RestHttpServer::stop(){
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
    RestEndpoint endpoint = restEndpoints.at(uri);

    RestClient restClient;
    restClient.setArguments();
    restClient.setHttpMethode(method);


    return endpoint.handleRestClient(restClient);
    //Todo: Return response data and maybe additional headers (?)
}

void RestHttpServer::answerClient(WifiClientResponse response) {
    WiFiClient client = response.getClient();


    std::vector<HttpHeader> headers = response.getHeaders();

    for(int i = 0; i < headers.size(); i++)
    {
        HttpHeader header = headers.at(i);
        //Todo: Send header name and content
    }

    HttpPayload payload = response.getPayload();
    //TODO: Send payload
}

void RestHttpServer::addEndpoint(String url, RestEndpoint endpoint) {
    restEndpoints.insert(std::pair<String, RestEndpoint>(url, endpoint));
}

void RestHttpServer::removeEndpoint(RestEndpoint endpoint) {
    //TODO: Implement methode
}



