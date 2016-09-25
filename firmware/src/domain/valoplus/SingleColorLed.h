#ifndef TEST_SINGLECOLORLED_H
#define TEST_SINGLECOLORLED_H

#include <string>
#include <domain/valoplus/ChannelElement.h>

class SingleColorLed : public ChannelElement {
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
