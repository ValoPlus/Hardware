cmake_minimum_required(VERSION 3.2)
project(firmware)

include(CMakeListsPrivate.txt)

add_definitions(-DF_CPU=80000000L)
add_definitions(-D__ets__)
add_definitions(-DICACHE_FLASH)
add_definitions(-DESP8266)
add_definitions(-DARDUINO_ARCH_ESP8266)
add_definitions(-DARDUINO_ESP8266_ESP12)
add_definitions(-DARDUINO=20200)
add_definitions(-DPLATFORMIO=020901)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(firmware
    src/main.cpp
    src/OTA/OTAManager.cpp
    src/Light/ChannelManager.cpp
    src/Helper/JsonHelper.cpp
    src/WebServer/WebServer.cpp
    src/Domain/Light/LED/LED.cpp
    src/Domain/Light/LED/ColorLed.cpp
    src/Domain/Light/Channel/WS2812Channel.cpp
    src/Domain/Light/Channel/PCA9685Channel.cpp
    src/Domain/Light/Channel/PCA9685SingleChannel.cpp
    src/Domain/Light/Channel/Channel.cpp
)
