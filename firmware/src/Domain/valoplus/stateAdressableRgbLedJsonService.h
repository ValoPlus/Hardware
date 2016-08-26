#ifndef TEST_STATEADRESSABLERGBLEDJSONSERVICE_H
#define TEST_STATEADRESSABLERGBLEDJSONSERVICE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <domain/valoplus/stateAdressableRgbLed.h>

class StateAdressableRgbLedJsonService {
private:

public:
	char* toJson(StateAdressableRgbLed obj) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();

		root("active") = obj.getActive();
		root("brightness") = obj.getBrightness();

        char buffer[root.measureLength()];
        root.printTo(buffer, sizeof(buffer));
        return buffer;
	}

	StateAdressableRgbLed* fromJson(String json) {
		StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.parseObject(json);

        StateAdressableRgbLed* result = new StateAdressableRgbLed();

        (*result).setActive(root("active"));
        (*result).setBrightness(root("brightness"));

        return result;
	}
};

#endif //TEST_STATEADRESSABLERGBLEDJSONSERVICE_H
