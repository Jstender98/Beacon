import numpy as np
import matplotlib.pyplot as plt

# Generate some random data for demonstration purposes
y = np.array([48.41, 36.88, 25.45, 17.19, 14.3, 17.57, 26.11, 37.64, 49.07, 57.33, 60.22, 56.95, 43.05, 31.63, 25.84, 31.47, 42.9, 48.68, 37.26])
x = np.array([63.87, 66.7, 63.37, 54.78, 43.23, 31.82, 23.61, 20.79, 24.12, 32.71, 44.25, 55.66, 53.62, 53.64, 43.76, 33.86, 33.84, 43.72, 43.74])
magnitudes_temp = np.random.rand(19) * 100
magnitudes_light = np.random.rand(19) * 100
# Create a scatter plot using matplotlib
fig, (ax0, ax1) = plt.subplots(1, 2)
im = ax0.scatter(x, y, c=magnitudes_temp, cmap='viridis', vmin=0, vmax=100)
cbar = ax0.figure.colorbar(im, ax=ax0)
ax0.set_title("Scatter Plot of Collected Data")
ax0.set_xlabel("X-axis Label")
ax0.set_ylabel("Y-axis Label")
# Create a scatter plot using matplotlib
im = ax1.scatter(x, y, c=magnitudes_light, cmap='viridis', vmin=0, vmax=100)
cbar = ax1.figure.colorbar(im, ax=ax1)
ax1.set_title("Scatter Plot of Collected Data")
ax1.set_xlabel("X-axis Label")
ax1.set_ylabel("Y-axis Label")
plt.show()