#Import the libraries : Pandas, Matplotlib and Seaborn
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

#Define the mean function
def mean(input_variable):
	calculated_value = 0
	for counter in range(0,100):
		calculated_value += input_variable.iloc[counter]
	calculated_value /= counter
	return calculated_value

#Define the variance function
def variance(input_variable,mean_value):
	for counter in range(0,100):
		calculated_value = input_variable.iloc[counter] - mean_value
		calculated_value = pow(calculated_value,2)
	calculated_value /= counter
	return calculated_value

#Define the standard deviation function
def stdev(variance_value):
	variance_value **= 0.5
	return variance_value

#Define the standard error function
def sterror(stdev_value):
	stdev_value /= pow(100,0.5)
	return stdev_value

#Define the drawing function
def draw_plot(values, title):
	sns.distplot(values, kde= False)
	plt.ylabel("Occurence of values")
	plt.xlabel(" ")
	plt.title(title)
	plt.show()

#Define the printing function
def printer(text, value):
	print(f'The mean value of {text} is :', mean(value))
	print(f'The variance value of {text} is :', variance(value, mean(value)))
	print(f'The standard deviation of {text} is :', 
		stdev(variance(value,mean(value))))
	print(f'The standard error of {text} is :', sterror(stdev(variance(value,mean(value)))))
	print('\n')

#Import data from the csv files and store them in defined lists
data = pd.read_csv('data.csv', delimiter=',', header=None, names=["counter","duration"])
droplets_data = pd.read_csv('droplets_data.csv', delimiter=';', header=None, 
					names=["occurence_3s","occurence_5s","occurence_10s"])

draw_plot(data["duration"], "Histogram of duration between droplets")
draw_plot(droplets_data["occurence_3s"], "Histogram of droplets per 3 sec")
draw_plot(droplets_data["occurence_5s"], "Histogram of droplets per 5 sec")
draw_plot(droplets_data["occurence_10s"], "Histogram of droplets per 10 sec")

#Print the calculations for mean, variance, standard deviation and standard error
printer("duration",data["duration"])
printer("droplets per 3 sec", droplets_data["occurence_3s"])
printer("droplets per 5 sec", droplets_data["occurence_5s"])
printer("droplets per 10 sec", droplets_data["occurence_10s"])