//
// Created by torben on 12.02.16.
//

#ifndef PLTEST_WEBSERVER_H
#define PLTEST_WEBSERVER_H

#include <ArduinoJson.h>


class WebServer {
public:
    void init();
    void handleClient();

private:
    void handleRoot();
    void handleNotFound();
    void handleInit();
    void handleChannel();
    void handleStatus();
    void handleSettings();



    bool isClientIdValid();


};


#endif //PLTEST_WEBSERVER_H
