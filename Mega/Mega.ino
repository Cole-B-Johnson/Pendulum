#include <SoftwareSerial.h>

SoftwareSerial pi_serial(15, 14);                           // Raspberry Pi Connection
SoftwareSerial imu_1_serial(13, 12);                        // IMU 1 Connection
SoftwareSerial imu_2_serial(11, 10);                        // IMU 2 Connection
String pi_serialBuff, imu_1_serialBuff, imu_2_serialBuff;   // Buffers for Messages
int stepPin = 5;
int dirPin = 6;
int enblPin = 7;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Starting Serial Communication...");

  pi_serial.begin(115200);
  while (!pi_serial);
  Serial("Starting Pi Communication...");
  
  imu_1_serial.begin(115200);
  while (!imu_1_serial);
  Serial("Starting IMU 1 Communication...");
  
  imu_2_serial.begin(115200);
  while (!imu_2_serial);
  Serial("Starting IMU 2 Communication...");

  pinMode (stepPin, OUTPUT);
  pinMode (dirPin, OUTPUT);
  pinMode (enblPin, OUTPUT);
}

void loop() {
  //            ----------- LISTEN FOR MESSAGES -------------
  while (pi_serial.available()) {                             // listen for messages from pi
    pi_serialBuff += String((char)pi_serial.read()); 
  }
  while (imu_1_serial.available()) {                          // listen for messages from pi
    imu_1_serialBuff += String((char)imu_1_serial.read()); 
  }
  while (imu_2_serial.available()) {                          // listen for messages from pi
    imu_2_serialBuff += String((char)imu_2_serial.read()); 
  }

  //            ----------- MOTOR ACTUATION -------------
  if (pi_serialBuff.length() > 0) {                           // if there is a new message to read from the pi
    Serial.println("Command Recieved: " + pi_serialBuff);     
    actuation_command = command_to_actuation(new_command);    // convert the signal to processable command
    actuate_motor(actuation_command);                         // actuate motor with command
  }

  //            ----------- THETA TRANSMISSION TO PI -------------
  if (imu_1_serialBuff.length() > 0 or imu_2_serialBuff.length() > 0) {      // if either of the theta values have been updated
    Serial.println("theta_1: " + String(theta_1) + ", theta_2: " + String(theta_2));
    pi_serial.println(theta_1 + "_" + theta_2);               // send the new theta values to the pi
  }
}

float command_to_actuation(command) {
  // returns the duration of the movement 
}

void actuate_motor(command) {
  for 
}










// reference code for motor actuation
int stepPin = 5;
int dirPin = 6;
int enblPin = 7;
void setup() {
pinMode (stepPin, OUTPUT);
pinMode (dirPin, OUTPUT);
pinMode (enblPin, OUTPUT);
digitalWrite(stepPin, LOW);
digitalWrite(dirPin, LOW);
digitalWrite(enblPin, HIGH);
}
void loop() {
for(int x=0; x<1600; x++){
digitalWrite(stepPin, HIGH);
delayMicroseconds(100);
digitalWrite(stepPin, LOW);
delayMicroseconds(100);
}
digitalWrite(enblPin, LOW);
exit(0);
}
