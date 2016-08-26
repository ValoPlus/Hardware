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

		root("name") = obj.getName();
		root("members") = obj.getMembers();

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	Group* fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        Group* result = new Group();

        (*result).setName(root("name"));
        (*result).setMembers(root("members"));

        return result;
	}
};

#endif //TEST_GROUPJSONSERVICE_H
