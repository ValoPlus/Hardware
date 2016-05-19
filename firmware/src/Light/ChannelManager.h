//
// Created by torben on 20.02.16.
//

#ifndef FIRMWARE_CHANNELMANAGER_H
#define FIRMWARE_CHANNELMANAGER_H

#include "../Domain/Light/Channel/WS2812Channel.h"
#include "../Domain/Light/Channel/PCA9685SingleChannel.h"
class ChannelManager {
private:
    
public:
    
    void addChannel(WS2812Channel& channel);
    void addChannel(PCA9685SingleChannel& channel);

    Channel getChannel(String& name);


    void removeChannel(WS2812Channel& channel);
    void removeChannel(PCA9685Channel& channel);

    void loadJson(String& json);
    String getJson();
    
};


#endif //FIRMWARE_CHANNELMANAGER_H
