//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_URLELEMENT_H
#define FIRMWARE_URLELEMENT_H


#include <RestHttpServer/Endpoint/RestEndpoint.h>
#include <LinkedList.h>

class RestUrlElement {

public:
    RestUrlElement();

    RestUrlElement(RestEndpoint& endpoint);


    void addElement(RestUrlElement element);



    RestEndpoint& getEndpoint();

    LinkedList<RestUrlElement*> getElements();

private:
    LinkedList<RestUrlElement*> elements;
    RestEndpoint& endpoint;
};


#endif //FIRMWARE_URLELEMENT_H
