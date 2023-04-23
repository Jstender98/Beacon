# Beacon Assessment of Light Penetration in Phantoms

import serial
import time
import datetime
import csv
#import matplotlib.pyplot as plt

def plot_data():
	t = []
	p = []

	filetime = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")

	with open("data_" + filetime + ".csv", 'w') as f:

		writer = csv.writer(f)

		while True:
			Serial0 = serial.Serial('/dev/ttyACM0', 9600, timeout=1) # all thermistors
			Serial1 = serial.Serial('/dev/ttyACM1', 9600, timeout=1) # all photoresistors
			Serial2 = serial.Serial('/dev/ttyACM2', 9600, timeout=1) # combo board

			s0 = Serial0.readline().split()
			s1 = Serial1.readline().split()
			s2 = Serial2.readline().split()

			print('S0: ', len(s0))
			print('S1: ', len(s1))
			print('S2: ', len(s2))
			print("------")

			l = 'ERROR'

			if((len(s0) == 16)):
				if((len(s1) == 16)):
					if((len(s2) == 6)):
						l1 = [s0, s2[0:3], s1, s2[3:6]]
						l = [element for sublist in l1 for element in sublist]
						l = [obj.decode() for obj in l]
			print(l)
			if l != 'ERROR':
				writer.writerow(l)
				print('file written')

			print("------")


if __name__ == '__main__':
	plot_data()

