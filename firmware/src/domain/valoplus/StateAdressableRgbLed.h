#ifndef TEST_STATEADRESSABLERGBLED_H
#define TEST_STATEADRESSABLERGBLED_H

#include <domain/valoplus/state.h>

class StateAdressableRgbLed : State {
	private:
		bool active;
		int brightness;
	public:
		bool getActive() { return this->active; }
		int getBrightness() { return this->brightness; }
		void setActive(bool active) { this->active = active; }
		void setBrightness(int brightness) { this->brightness = brightness; }
};

#endif //TEST_STATEADRESSABLERGBLED_H
