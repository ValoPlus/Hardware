//
// Created by torben on 8/22/16.
//

#include "UrlToEndpointMapper.h"
#include "UndefinedEndpoint.h"

RestEndpoint& UrlToEndpointMapper::mapUrl(Url url) {

    LinkedList<UrlPathElement*> path = url.getPathElements();

    return traverseTree(path, this->restUrlTreeRoot);
}

RestEndpoint& UrlToEndpointMapper::traverseTree(LinkedList<UrlPathElement*> remainingPath, RestUrlElement currentNode) {
/*
    //TODO: If a Placeholder is found, store it somewhere so the RestEndpoint can access it.
    //TODO: Handle query parameters
    if(remainingPath.size() == 1){
        return currentNode.getEndpoint();
    }
    else{
        //TODO: Check for every RestUrlConstantElement in currentNode and continue traversing. If no matching RestUrlConstant Element ist found check for RestUrlPlaceholder and continue traversing. If not matching RestUrlPlaceholder is found return the Endpoint of currentNode (which should be a UndefinedEndpoint because there are still UrlPathElements left).
        //LinkedList<RestUrlElement> currentElements = currentNode.getElements();

      //  for(int i = 0; i < currentElements.size(); i++){
           // if(currentElements->get(i).matches(remainingPath.get(0))){

           // }

      //  }

    }
*/
    return  UndefinedEndpoint::getInstance();
}



