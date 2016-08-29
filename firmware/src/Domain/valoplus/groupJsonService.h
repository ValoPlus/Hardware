#ifndef TEST_GROUPJSONSERVICE_H
#define TEST_GROUPJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/group.h>

class GroupJsonService {
private:

public:
	char* toJson(Group obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name", obj.getName());
		root("members", obj.getMembers());

		JsonObject& links = root.createNestedObject("_links");

		JsonObject& self1 = links.createNestedObject("self");
		self1.set("href", "/groups/" + obj.getId());
		JsonObject& self2 = links.createNestedObject("group");
		self2.set("href", "/groups/" + obj.getId());

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	Group fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        Group result = Group();

        result.setName(root("name"));
        result.setMembers(root("members"));

        return result;
	}
};

#endif //TEST_GROUPJSONSERVICE_H
