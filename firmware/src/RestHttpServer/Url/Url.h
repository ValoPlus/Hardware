//
// Created by torben on 8/22/16.
//

#ifndef FIRMWARE_URL_H
#define FIRMWARE_URL_H


#include <LinkedList.h>
#include "UrlPathElement.h"

class Url {

private:
    LinkedList<UrlPathElement*> path;

public:
    LinkedList<UrlPathElement*> getPathElements();
};


#endif //FIRMWARE_URL_H
