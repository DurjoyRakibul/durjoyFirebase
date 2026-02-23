#include <durjoyFirebase.h>

durjoyFirebase firebase(
  "Your_WiFi_Name",
  "Your_WiFi_Password",
  "https://your-project-id-default-rtdb.firebaseio.com"
);

void setup() {
  Serial.begin(115200);
  firebase.begin();
}

void loop() {

  float temperature = random(20, 35);

  if (firebase.sendFloat("sensor/temperature", temperature)) {
    Serial.println("Sent!");
  } else {
    Serial.println("Failed!");
  }

  delay(5000);
}