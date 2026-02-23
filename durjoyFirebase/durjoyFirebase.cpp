#include "durjoyFirebase.h"

durjoyFirebase::durjoyFirebase(const char* ssid,
                                 const char* password,
                                 const char* databaseURL) {

  _ssid = ssid;
  _password = password;
  _databaseURL = databaseURL;
}

void durjoyFirebase::begin() {

  WiFi.begin(_ssid, _password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

bool durjoyFirebase::sendFloat(String path, float value) {

  if (WiFi.status() != WL_CONNECTED)
    return false;

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient https;

  String fullURL = String(_databaseURL) + "/" + path + ".json";

  if (https.begin(client, fullURL)) {

    https.addHeader("Content-Type", "application/json");

    String jsonData = String(value);

    int httpCode = https.PUT(jsonData);

    https.end();

    if (httpCode > 0)
      return true;
  }

  return false;
}

bool durjoyFirebase::sendString(String path, String value) {

  if (WiFi.status() != WL_CONNECTED)
    return false;

  WiFiClientSecure client;
  client.setInsecure();

  HTTPClient https;

  String fullURL = String(_databaseURL) + "/" + path + ".json";

  if (https.begin(client, fullURL)) {

    https.addHeader("Content-Type", "application/json");

    String jsonData = "\"" + value + "\"";

    int httpCode = https.PUT(jsonData);

    https.end();

    if (httpCode > 0)
      return true;
  }

  return false;
}
