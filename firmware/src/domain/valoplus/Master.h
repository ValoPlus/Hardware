#ifndef TEST_MASTER_H
#define TEST_MASTER_H

#include <string>
#include <domain/valoplus/Device.h>
#include <vector>
#include <domain/valoplus/ChannelElement.h>

class Master : public Device {
	private:
		std::string name;
		std::string ip;
		std::string key;
		int maxChannel;
		bool isConfigured;
		std::vector<ChannelElement> elements;
		std::string password;
	public:
		std::string getName() { return this->name; }
		std::string getIp() { return this->ip; }
		std::string getKey() { return this->key; }
		int getMaxChannel() { return this->maxChannel; }
		bool getIsConfigured() { return this->isConfigured; }
		std::vector<ChannelElement> getElements() { return this->elements; }
		std::string getPassword() { return this->password; }
		void setName(std::string name) { this->name = name; }
		void setIp(std::string ip) { this->ip = ip; }
		void setKey(std::string key) { this->key = key; }
		void setMaxChannel(int maxChannel) { this->maxChannel = maxChannel; }
		void setIsConfigured(bool isConfigured) { this->isConfigured = isConfigured; }
		void setElements(std::vector<ChannelElement> elements) { this->elements = elements; }
		void setPassword(std::string password) { this->password = password; }
};

#endif //TEST_MASTER_H
