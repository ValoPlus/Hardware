#ifndef TEST_RGBLED_H
#define TEST_RGBLED_H

#include <string>
#include <domain/valoplus/ChannelElement.h>

class RgbLed : public ChannelElement {
	private:
		std::string name;
		int channelIdRed;
		int channelIdGreen;
		int channelIdBlue;
	public:
		std::string getName() { return this->name; }
		int getChannelIdRed() { return this->channelIdRed; }
		int getChannelIdGreen() { return this->channelIdGreen; }
		int getChannelIdBlue() { return this->channelIdBlue; }
		void setName(std::string name) { this->name = name; }
		void setChannelIdRed(int channelIdRed) { this->channelIdRed = channelIdRed; }
		void setChannelIdGreen(int channelIdGreen) { this->channelIdGreen = channelIdGreen; }
		void setChannelIdBlue(int channelIdBlue) { this->channelIdBlue = channelIdBlue; }
};

#endif //TEST_RGBLED_H
