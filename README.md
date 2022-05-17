# Double Inverted Pendulum Control
This project consists of a double inverted pendulum actuated from the origin point linearly in one dimension. This is achieved using a cart actuated using a belt along a linear rail system. Both arms of the pendulum transmit IMU data using HC-05 bluetooth to an arduino Mega which, in turn, transmits to a Raspberry Pi -- the main calculating engine -- and actuates a motor in order to accelerate the cart along the rail.

This repository is dedicated to the firmware used in this system as well as the control architecture used by the Raspberry Pi in order accurately predict 1) the motion of the pendulum and 2) the necessary actuation in order to control the arms of the pendulum in a desired manner.
