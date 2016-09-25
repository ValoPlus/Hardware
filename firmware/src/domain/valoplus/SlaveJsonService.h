#ifndef TEST_SLAVEJSONSERVICE_H
#define TEST_SLAVEJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/Slave.h>

class SlaveJsonService {
private:

public:
	char* toJson(Slave obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name", obj.getName());
		root("ip", obj.getIp());
		root("key", obj.getKey());
		root("maxChannel", obj.getMaxChannel());
		root("isConfigured", obj.getIsConfigured());
		root("elements", obj.getElements());

		JsonObject& links = root.createNestedObject("_links");

		JsonObject& self1 = links.createNestedObject("self");
		self1.set("href", "/slaves/" + obj.getTableRow());
		JsonObject& self2 = links.createNestedObject("slave");
		self2.set("href", "/slaves/" + obj.getTableRow());

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	Slave fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        Slave result = Slave();

        result.setName(root("name"));
        result.setIp(root("ip"));
        result.setKey(root("key"));
        result.setMaxChannel(root("maxChannel"));
        result.setIsConfigured(root("isConfigured"));
        result.setElements(root("elements"));

        return result;
	}
};

#endif //TEST_SLAVEJSONSERVICE_H
