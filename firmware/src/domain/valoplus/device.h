#ifndef TEST_DEVICE_H
#define TEST_DEVICE_H

#include <domain/valoplus/channelElement.h>
#include <string>
#include <domain/valoplus/controllableElement.h>
#include <vector>

class Device : ControllableElement {
	private:
		
	public:
		virtual std::string getIp()= 0;
		virtual std::string getKey()= 0;
		virtual int getMaxChannel()= 0;
		virtual bool getIsConfigured()= 0;
		virtual std::vector<ChannelElement> getElements()= 0;
		virtual void setIp(std::string ip)= 0;
		virtual void setKey(std::string key)= 0;
		virtual void setMaxChannel(int maxChannel)= 0;
		virtual void setIsConfigured(bool isConfigured)= 0;
		virtual void setElements(std::vector<ChannelElement> elements)= 0;
};

#endif //TEST_DEVICE_H
