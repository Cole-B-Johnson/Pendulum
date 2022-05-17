#include <SoftwareSerial.h>
#include <MPU6050.h>
SoftwareSerial imu_1_serial(15, 14);                        // IMU 1 Connection
Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Starting Serial Communication...");

  imu_1_serial.begin(115200);
  while (!pi_serial);
  Serial("Starting Pi Communication...");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G));
  Serial("Starting IMU Reading");
}

void loop() {
  //            ----------- READ DATA FROM IMU UNIT --------------
  sensors_event_t a, g;
  mpu.getEvent(&a, &g);
  theta_1[0] = a.acceleration.x
  theta_1[1] = g.gyro.x
  //            ----------- THETA TRANSMISSION TO MEGA -------------
  Serial.println("theta_1: " + String(theta_1));
  pi_serial.println(theta_1);               // send the new theta values to the pi
}
