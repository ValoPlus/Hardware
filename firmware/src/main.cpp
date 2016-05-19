#include <ESP8266WiFi.h>

#include <FS.h>


#include "OTA/OTAManager.h"

#include "WebServer/WebServer.h"
#include "Domain/Settings/Wlan/JsonWlanSettingsInput.h"
#include "Domain/Settings/Wlan/WlanSettings.h"
#include "Domain/Settings/JsonSettingsInput.h"
#include "Domain/Settings/Settings.h"


//const char *ssid = "";
//const char *password = "";

WebServer webServer;
OTAManager otaManager;


void bootstrap(){

    Serial.println("Bootstraping device");

    File f;


    String channelJsonPath = "/channel.json";

    if(SPIFFS.exists(channelJsonPath)){
        SPIFFS.remove(channelJsonPath);
    }

    f = SPIFFS.open(channelJsonPath, "w");
    f.println("[]");
    f.flush();
    f.close();


    String settingsJsonPath = "/settings.json";
    if(SPIFFS.exists(settingsJsonPath)){
        SPIFFS.remove(settingsJsonPath);
    }

    f = SPIFFS.open(settingsJsonPath, "w");
    f.println("{}");
    f.flush();
    f.close();

}


void startAP(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP("ValoPlus", "pw");
    Serial.print("Startet AP. IP: ");
    Serial.println(WiFi.softAPIP());

}
void setup() {
    Serial.begin(115200);
    Serial.println("Booting");


    Serial.println("Init SPIFFS");
    SPIFFS.begin();

    //SPIFFS.remove("/settings.json");


    if(SPIFFS.exists("/settings.json")) {
        Serial.println("Trying to read settings.json");

        String wifiPath = "/settings.json";
        File f = SPIFFS.open(wifiPath, "r");
        Serial.println("opend");

        String settingsJson = f.readString();
        Serial.println("read: " + settingsJson);
        f.close();
        Serial.println("closed");

        if (settingsJson.length() > 5) {
        JsonSettingsInput settingsInput = JsonSettingsInput(settingsJson);
        Settings settings = Settings(settingsInput);
        WlanSettings wifiConfig = settings.getWlanSettings();

        Serial.println("starting wlan");
        WiFi.mode(WIFI_STA);
        WiFi.begin(wifiConfig.getSSID().c_str(), wifiConfig.getPassword().c_str());

        if(WiFi.waitForConnectResult() != WL_CONNECTED) {
            Serial.println("Connection Failed! Starting AP...");
            startAP();
        }
        }
        else
        {
            startAP();
        }


    }
    else{
        bootstrap();
        startAP();
    }


    Serial.println("Wifi Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Starting OTA Manager... ");
    otaManager = OTAManager();
    otaManager.init();
    Serial.print("done.");


    Serial.println("Starting WebServer... ");
    webServer = WebServer();
    webServer.init();
    Serial.print("done.");

}

void loop() {
    otaManager.handle();
    webServer.handleClient();
}