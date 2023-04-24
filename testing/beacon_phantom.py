# Beacon Assessment of Light Penetration in Phantoms

import serial
import time
import datetime
import csv
import numpy as np
import matplotlib.pyplot as plt
import sys


# Create a scatter plot using matplotlib

def plot_data(x, y):

	fig, (ax0, ax1) = plt.subplots(1, 2)

	filetime = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")

	im0 = ax0.scatter(x, y, c=np.zeros(19), cmap='viridis', vmin=0, vmax=100000)
	cbar0 = ax0.figure.colorbar(im0, ax=ax0)
	ax0.set_title("Scatter Plot of Thermistor Data")
	ax0.set_xlabel("X-axis Label")
	ax0.set_ylabel("Y-axis Label")

	im1 = ax1.scatter(x, y, c=np.zeros(19), cmap='viridis', vmin=0, vmax=10000)
	cbar1 = ax1.figure.colorbar(im1, ax=ax1)
	ax1.set_title("Scatter Plot of Photoresistor Data")
	ax1.set_xlabel("X-axis Label")
	ax1.set_ylabel("Y-axis Label")

	plt.ion()
	plt.show()

	#sys.exit()

	with open("data_" + filetime + ".csv", 'w') as f:

		writer = csv.writer(f)

		while True:
			Serial0 = serial.Serial('/dev/ttyACM0', 9600, timeout=1) # all thermistors
			Serial1 = serial.Serial('/dev/ttyACM1', 9600, timeout=1) # all photoresistors
			Serial2 = serial.Serial('/dev/ttyACM2', 9600, timeout=1) # combo board

			s0 = Serial0.readline().split(b', ')
			s1 = Serial1.readline().split(b', ')
			s2 = Serial2.readline().split(b', ')

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
						l = [float(obj.decode()) for obj in l]
			print(l)
			if l != 'ERROR':
				writer.writerow(l)
				print('file written')

				magnitudes_light = np.array(l[19:38])
				magnitudes_temp = np.array(l[0:19])
				im0 = ax0.scatter(x, y, c=magnitudes_temp, cmap='viridis', vmin=0, vmax=100000)
				im1 = ax1.scatter(x, y, c=magnitudes_light, cmap='viridis', vmin=0, vmax=max(magnitudes_light))
				# Create a scatter plot using matplotlib
				
				fig.canvas.draw()

			print("------")
			plt.pause(0.001)


if __name__ == '__main__':
	y = np.array([48.41, 36.88, 25.45, 17.19, 14.3, 17.57, 26.11, 37.64, 49.07, 57.33, 60.22, 56.95, 43.05, 31.63, 25.84, 31.47, 42.9, 48.68, 37.26])
	x = np.array([63.87, 66.7, 63.37, 54.78, 43.23, 31.82, 23.61, 20.79, 24.12, 32.71, 44.25, 55.66, 53.62, 53.64, 43.76, 33.86, 33.84, 43.72, 43.74])

	plot_data(x, y)

