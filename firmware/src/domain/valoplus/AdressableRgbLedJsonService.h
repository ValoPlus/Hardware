#ifndef TEST_ADRESSABLERGBLEDJSONSERVICE_H
#define TEST_ADRESSABLERGBLEDJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/AdressableRgbLed.h>

class AdressableRgbLedJsonService {
private:

public:
	char* toJson(AdressableRgbLed obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("name", obj.getName());
		root("stateAdressableRgbLed", obj.getStateAdressableRgbLed());
		root("channelId", obj.getChannelId());
		root("ledCount", obj.getLedCount());

		JsonObject& links = root.createNestedObject("_links");

		JsonObject& self1 = links.createNestedObject("self");
		self1.set("href", "/adressableRgbLeds/" + obj.getTableRow());
		JsonObject& self2 = links.createNestedObject("adressableRgbLed");
		self2.set("href", "/adressableRgbLeds/" + obj.getTableRow());

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	AdressableRgbLed fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        AdressableRgbLed result = AdressableRgbLed();

        result.setName(root("name"));
        result.setStateAdressableRgbLed(root("stateAdressableRgbLed"));
        result.setChannelId(root("channelId"));
        result.setLedCount(root("ledCount"));

        return result;
	}
};

#endif //TEST_ADRESSABLERGBLEDJSONSERVICE_H
