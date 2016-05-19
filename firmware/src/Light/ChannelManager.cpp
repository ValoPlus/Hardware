//
// Created by torben on 20.02.16.
//

#include "ChannelManager.h"


std::vector<PCA9685SingleChannel> pca;


void ChannelManager::addChannel(PCA9685SingleChannel& channel) {
    pca.push_back(channel);
}

void ChannelManager::addChannel(WS2812Channel& channel) {

}

void ChannelManager::removeChannel(PCA9685Channel& channel) {

}