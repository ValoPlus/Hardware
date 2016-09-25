#ifndef ESP32_PERSISTSERVICE_H
#define ESP32_PERSISTSERVICE_H

#include <string>
#include "PersistentElement.h"

/**
 *  This service is used to access and save elements in the storage.
 *  Each non abstract class will managed in his own class. Abstract types are read only (sorted by type if read as list)
 */
class PersistentService {
private:

public:
    virtual void save(PersistentElement elementToSave)= 0;
    virtual void remove(PersistentElement elementToSave)= 0;
    virtual void remove(std::string type, int id)= 0;
    virtual PersistentElement get(std::string type)= 0;
    virtual PersistentElement get(std::string type, int id)= 0;

    virtual void rearangeStorage()=0;
};

#endif //ESP32_PERSISTSERVICE_H
