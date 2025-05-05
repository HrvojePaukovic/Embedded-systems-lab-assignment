#include <Arduino_LSM9DS1.h>   // IMU: Gyroscope and Magnetometer
#include <Arduino_LPS22HB.h>   // Pressure sensor
#include <Arduino_HTS221.h>    // Temperature and Humidity sensor
#include <Arduino_APDS9960.h>  // Gesture sensor

void setup() {
  Serial.begin(9600);
  while (!Serial);
  delay(1000);  // Give sensors time to power up

  IMU.begin();
  HTS.begin();
  BARO.begin();
  APDS.begin();

  Serial.println("All sensors initialized.");
}

void loop() {
  // Gyroscope
  float gx, gy, gz;
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(gx, gy, gz);
    Serial.print("Gyroscope (°/s): ");
    Serial.print(gx); Serial.print(", ");
    Serial.print(gy); Serial.print(", ");
    Serial.println(gz);
  }

  // Magnetometer
  float mx, my, mz;
  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(mx, my, mz);
    Serial.print("Magnetometer (µT): ");
    Serial.print(mx); Serial.print(", ");
    Serial.print(my); Serial.print(", ");
    Serial.println(mz);
  }

  // Temperature and Humidity
  float temperature = HTS.readTemperature();
  float humidity = HTS.readHumidity();
  Serial.print("Temperature (°C): "); Serial.print(temperature);
  Serial.print(" | Humidity (%): "); Serial.println(humidity);

  // Pressure
  float pressure = BARO.readPressure();
  Serial.print("Pressure (hPa): ");
  Serial.println(pressure);

  // Gesture
  if (APDS.gestureAvailable()) {
    int gesture = APDS.readGesture();
    Serial.print("Gesture code: ");
    Serial.println(gesture);
  }

  Serial.println("--------------------------");
  delay(2000);
}
