import pandas as pd
import matplotlib.pyplot as plt

def draw(filename):
	df = pd.read_csv(filename, delimiter=",", header=None,
			names=["output_DAC","input_DAC","output_LED","current"])

	plt.plot(df['output_LED'],df['current'], linewidth=2.5)
	plt.xlabel("Voltage of the LED in V")
	plt.ylabel("Current of the LED in mA")
	plt.title("The I vs V characteristic of an LED")
	plt.show()

draw("data.csv")
