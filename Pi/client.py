#!/usr/bin/env python3

import time
import serial
from utils import *
import os


def main():
    # path will be created for command and theta vectors to be written - ~/trial_[trial #]
    path_dir = f'{os.getcwd()}/{new_trial_name(os.getcwd())}/'
    frequency_of_refresh = 100 # hz that commands and theta vectors will be transmitted and checked at

    # making path at beginning of trial
    if not os.path.exists(path_dir):
        os.mkdir(path_dir)

    # connecting to serial for Mega communication (command transfer)
    ser = serial.Serial(
        port='/dev/rfcomm0',
        baudrate=115200,
        parity=serial.PARITY_ODD,
        stopbits=serial.STOPBITS_TWO,
        bytesize=serial.SEVENBITS
    )

    if ser.isOpen() == False:
        ser.open()

    while True:
        # get new commands from control.py and write to serial for actuation
        latest_command, newest_command_time = get_latest_command(path_dir)
        if newest_command_time() > last_write_time:
            print(f'Last Command Recieved: {latest_command}')
            ser.write(latest_command.encode())
            last_write_time = time.time()

        # get new theta readings from two HC-05 units and write to file for control.py to process
        recv = ''
        tic = time.time()
        while time.time() - tic < 15 and ser.inWaiting() == 0: 
            time.sleep(1 / frequency_of_refresh)

        if ser.inWaiting() > 0:
            line = ser.readline().split('_')
            theta1, theta2 = [float(line[0][0]), float(line[0][1])], 
                             [float(line[1][0]), float(line[1][1])]

        if recv != '':
            transmit_thetas(path_dir, theta1, theta2)
            print(f'theta_1 = {str(theta1, 'utf-8')}, theta_2 = {str(theta2, 'utf-8')}')


