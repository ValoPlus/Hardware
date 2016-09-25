#ifndef TEST_ADRESSABLERGBLED_H
#define TEST_ADRESSABLERGBLED_H

#include <domain/valoplus/StateAdressableRgbLed.h>
#include <string>
#include <domain/valoplus/ChannelElement.h>

class AdressableRgbLed : public ChannelElement {
	private:
		std::string name;
		StateAdressableRgbLed stateAdressableRgbLed;
		int channelId;
		int ledCount;
	public:
		std::string getName() { return this->name; }
		StateAdressableRgbLed getStateAdressableRgbLed() { return this->stateAdressableRgbLed; }
		int getChannelId() { return this->channelId; }
		int getLedCount() { return this->ledCount; }
		void setName(std::string name) { this->name = name; }
		void setStateAdressableRgbLed(StateAdressableRgbLed stateAdressableRgbLed) { this->stateAdressableRgbLed = stateAdressableRgbLed; }
		void setChannelId(int channelId) { this->channelId = channelId; }
		void setLedCount(int ledCount) { this->ledCount = ledCount; }
};

#endif //TEST_ADRESSABLERGBLED_H
