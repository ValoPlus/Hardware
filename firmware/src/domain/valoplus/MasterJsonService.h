#ifndef TEST_MASTERJSONSERVICE_H
#define TEST_MASTERJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/Master.h>

class MasterJsonService {
private:

public:
	char* toJson(Master obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name", obj.getName());
		root("ip", obj.getIp());
		root("key", obj.getKey());
		root("maxChannel", obj.getMaxChannel());
		root("isConfigured", obj.getIsConfigured());
		root("elements", obj.getElements());
		root("password", obj.getPassword());

		JsonObject& links = root.createNestedObject("_links");

		JsonObject& self1 = links.createNestedObject("self");
		self1.set("href", "/masters/" + obj.getTableRow());
		JsonObject& self2 = links.createNestedObject("master");
		self2.set("href", "/masters/" + obj.getTableRow());

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	Master fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        Master result = Master();

        result.setName(root("name"));
        result.setIp(root("ip"));
        result.setKey(root("key"));
        result.setMaxChannel(root("maxChannel"));
        result.setIsConfigured(root("isConfigured"));
        result.setElements(root("elements"));
        result.setPassword(root("password"));

        return result;
	}
};

#endif //TEST_MASTERJSONSERVICE_H
