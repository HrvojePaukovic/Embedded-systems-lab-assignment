#include <Arduino_LSM9DS1.h>

float calculateAngle(float x, float y, float z) {
  // Pitch  = atan2(Y, sqrt(X*X + Z*Z))
  return atan2(y, sqrt(x*x + z*z)) * 180.0 / PI;
}

void setup() {
  Serial.begin(9600);
  while (!Serial);           // wait for Serial Monitor
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.println("IMU initialized");
}

void loop() {
  float x, y, z;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    float pitch = calculateAngle(x, y, z);
    Serial.print("Pitch (°): ");
    Serial.println(pitch);

    delay(2000);  // print every 2 seconds
  }
}
