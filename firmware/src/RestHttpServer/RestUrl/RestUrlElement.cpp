//
// Created by torben on 8/22/16.
//

#include "RestUrlElement.h"
#include "RestHttpServer/Endpoint/UndefinedEndpoint.h"

RestUrlElement::RestUrlElement() : RestUrlElement(endpoint = UndefinedEndpoint::getInstance()){
}

RestUrlElement::RestUrlElement(RestEndpoint& endpoint) : RestUrlElement(this->endpoint = endpoint){

}



RestEndpoint& RestUrlElement::getEndpoint() {
    return this->endpoint;
}

LinkedList<RestUrlElement*> RestUrlElement::getElements() {
    return this->elements;
}

void RestUrlElement::addElement(RestUrlElement element) {

}

