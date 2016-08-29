//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_URLTOENDPOINTMAPPER_H
#define FIRMWARE_URLTOENDPOINTMAPPER_H


#include <RestHttpServer/RestUrl/RestUrlElement.h>
#include "RestEndpoint.h"
#include "RestHttpServer/Url/Url.h"

class UrlToEndpointMapper {

private:
    RestUrlElement restUrlTreeRoot;

    RestEndpoint& traverseTree(LinkedList<UrlPathElement*> remainingPath, RestUrlElement currentNode);

public:
    RestEndpoint& mapUrl(Url url);

};


#endif //FIRMWARE_URLTOENDPOINTMAPPER_H
