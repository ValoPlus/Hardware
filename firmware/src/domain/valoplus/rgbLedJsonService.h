#ifndef TEST_RGBLEDJSONSERVICE_H
#define TEST_RGBLEDJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/rgbLed.h>

class RgbLedJsonService {
private:

public:
	char* toJson(RgbLed obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name", obj.getName());
		root("channelIdRed", obj.getChannelIdRed());
		root("channelIdGreen", obj.getChannelIdGreen());
		root("channelIdBlue", obj.getChannelIdBlue());

		JsonObject& links = root.createNestedObject("_links");

		JsonObject& self1 = links.createNestedObject("self");
		self1.set("href", "/rgbLeds/" + obj.getId());
		JsonObject& self2 = links.createNestedObject("rgbLed");
		self2.set("href", "/rgbLeds/" + obj.getId());

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	RgbLed fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        RgbLed result = RgbLed();

        result.setName(root("name"));
        result.setChannelIdRed(root("channelIdRed"));
        result.setChannelIdGreen(root("channelIdGreen"));
        result.setChannelIdBlue(root("channelIdBlue"));

        return result;
	}
};

#endif //TEST_RGBLEDJSONSERVICE_H
