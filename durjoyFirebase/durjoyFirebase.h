#ifndef DURJOY_FIREBASE_H
#define DURJOY_FIREBASE_H

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

class durjoyFirebase {

  private:
    const char* _ssid;
    const char* _password;
    const char* _databaseURL;

  public:
    durjoyFirebase(const char* ssid,
                    const char* password,
                    const char* databaseURL);

    void begin();
    bool sendFloat(String path, float value);
    bool sendString(String path, String value);
};

#endif
