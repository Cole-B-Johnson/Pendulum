#!/usr/bin/env python3

import os
import json
import time

def transmit_thetas(path_dir, theta_1, theta_2):
	y = {time.time(): {'theta1': theta_1, 'theta_2': theta_2}}
 	z = json.loads(f'{path_dir}theta_values.json')
	z.update(y)
	z.dump(f'{path_dir}theta_values.json')

def transmit_command(path_dir, command):
	y = {time.time(): command}
 	z = json.loads(f'{path_dir}commands.json')
	z.update(y)
	z.dump(f'{path_dir}commands.json')

def get_latest_command(path_dir):
	commands = json.load(f'{path_dir}commands.json')
	latest_time_stamp = max(list(commands.keys()))
	return commands[latest_time_stamp], latest_time_stamp

def get_commands(path_dir):
	return json.load(f'{path_dir}commands.json')

def get_thetas(path_dir):
	return json.load(f'{path_dir}theta_values.json')

def new_trial_name(path_dir):
	files_present = [int(d.split('_')[-1]) for d in os.listdir(path_dir) if os.path.isdir(os.path.join(path_dir, d))]
	new_index = max(files_present) + 1
	return 'trial_' + str(new_index)