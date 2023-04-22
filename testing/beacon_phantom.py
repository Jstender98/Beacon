# Beacon Assessment of Light Penetration in Phantoms

import serial
import time
#import matplotlib.pyplot as plt

def plot_data():
	t = []
	p = []

	Serial0 = serial.Serial('/dev/ttyACM0', 9600, timeout=1) # all thermistors
	Serial1 = serial.Serial('/dev/ttyACM1', 9600, timeout=1) # all photoresistors
	#Serial2 = serial.Serial('/dev/ttyACM2', 9600, timeout=1) # combo board

	#fig, ax = plt.figure()

	while True:
		print('S0: ', Serial0.readline())
		print('S1: ', Serial1.readline())
		#print('S2: ', Serial2)

if __name__ == '__main__':
	plot_data()