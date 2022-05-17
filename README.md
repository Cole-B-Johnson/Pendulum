# Double Inverted Pendulum Control
This project consists of a double inverted pendulum actuated from the origin point linearly in one dimension. This is achieved using a cart actuated using a belt along a linear rail system. Both arms of the pendulum transmit IMU data using HC-05 bluetooth to an arduino Mega which, in turn, transmits to a Raspberry Pi -- the main calculating engine -- and actuates a motor in order to accelerate the cart along the rail.

This repository is dedicated to the firmware used in this system as well as the control architecture used by the Raspberry Pi in order accurately predict 1) the motion of the pendulum and 2) the necessary actuation in order to control the arms of the pendulum in a desired manner.

Organization:
- Control.py
  - Where all the mathematical calculations occur for the prediction of pendulum motion and control actuation 
- Client.py
  - Where the interfacing code for Mega - Pi interactions occur (transfer of theta values from Mega to Pi, transfer of commands from Pi to Mega)
- Utils.py
  - Where some useful methods are stored
- Arduino Code:
  - Mega
    - Recieve bluetooth signals from both IMU (Arduino Nano) units
    - Recieve bluetooth signal from Raspberry Pi and actuate motor in accordance with commands
    - Transfer bluetooth signal to Raspberry Pi representing theta vectors received from IMU units
  - Nanos
    - Similar codes for IMU unit 1 and IMU unit 2
    - Read x-axis acceleratiion and theta values from MPU6050 IMU sensor and transmit values in vector using HC-05 bluetooth module to Mega
