#include <Wire.h>
#include <MAX30105.h> 

MAX30105 particleSensor;
void setup() {
  Serial.begin(115200);
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    while (1);
  }
  particleSensor.setup(); 
  particleSensor.setPulseAmplitudeRed(0x0A); 
}

void loop() {
  long irValue = particleSensor.getIR();
  if (irValue > 50000) { 
    Serial.println("Heartbeat detected!");
  } else {
    Serial.println("No heartbeat detected");
  }
  delay(200);
}