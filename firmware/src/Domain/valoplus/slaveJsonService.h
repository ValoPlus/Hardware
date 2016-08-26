#ifndef TEST_SLAVEJSONSERVICE_H
#define TEST_SLAVEJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/slave.h>

class SlaveJsonService {
private:

public:
	char* toJson(Slave obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name") = obj.getName();
		root("ip") = obj.getIp();
		root("key") = obj.getKey();
		root("maxChannel") = obj.getMaxChannel();
		root("isConfigured") = obj.getIsConfigured();
		root("elements") = obj.getElements();

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	Slave* fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        Slave* result = new Slave();

        (*result).setName(root("name"));
        (*result).setIp(root("ip"));
        (*result).setKey(root("key"));
        (*result).setMaxChannel(root("maxChannel"));
        (*result).setIsConfigured(root("isConfigured"));
        (*result).setElements(root("elements"));

        return result;
	}
};

#endif //TEST_SLAVEJSONSERVICE_H
