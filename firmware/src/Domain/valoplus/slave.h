#ifndef TEST_SLAVE_H
#define TEST_SLAVE_H

#include <domain/valoplus/channelElement.h>
#include <string>
#include <domain/valoplus/device.h>
#include <vector>

class Slave : Device {
	private:
		std::string name;
		std::string ip;
		std::string key;
		int maxChannel;
		bool isConfigured;
		std::vector<ChannelElement> elements;
	public:
		std::string getName() { return this->name; }
		std::string getIp() { return this->ip; }
		std::string getKey() { return this->key; }
		int getMaxChannel() { return this->maxChannel; }
		bool getIsConfigured() { return this->isConfigured; }
		std::vector<ChannelElement> getElements() { return this->elements; }
		void setName(std::string name) { this->name = name; }
		void setIp(std::string ip) { this->ip = ip; }
		void setKey(std::string key) { this->key = key; }
		void setMaxChannel(int maxChannel) { this->maxChannel = maxChannel; }
		void setIsConfigured(bool isConfigured) { this->isConfigured = isConfigured; }
		void setElements(std::vector<ChannelElement> elements) { this->elements = elements; }
};

#endif //TEST_SLAVE_H
