#ifndef TEST_SINGLECOLORLEDJSONSERVICE_H
#define TEST_SINGLECOLORLEDJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/singleColorLed.h>

class SingleColorLedJsonService {
private:

public:
	char* toJson(SingleColorLed obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name") = obj.getName();
		root("channelId") = obj.getChannelId();

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	SingleColorLed* fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        SingleColorLed* result = new SingleColorLed();

        (*result).setName(root("name"));
        (*result).setChannelId(root("channelId"));

        return result;
	}
};

#endif //TEST_SINGLECOLORLEDJSONSERVICE_H
