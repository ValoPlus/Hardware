#ifndef TEST_SINGLECOLORLED_H
#define TEST_SINGLECOLORLED_H

#include <domain/valoplus/channelElement.h>
#include <string>

class SingleColorLed : ChannelElement {
	private:
		std::string name;
		int channelId;
	public:
		std::string getName() { return this->name; }
		int getChannelId() { return this->channelId; }
		void setName(std::string name) { this->name = name; }
		void setChannelId(int channelId) { this->channelId = channelId; }
};

#endif //TEST_SINGLECOLORLED_H
