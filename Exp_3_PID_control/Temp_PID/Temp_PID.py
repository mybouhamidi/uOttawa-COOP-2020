# Import the libraries : Pandas and Matplotlib
import pandas as pd
import matplotlib.pyplot as plt 
from dateutil.parser import parse

# Read the csv file data
data = pd.read_csv("Test.csv", header=None, delimiter='->', engine='python', names=['time','temp'])

# Data manipulation to store the right data into the variables
temporary_temp = [item for item in data.temp]
time_list = [item for item in data.time]

# remove strings and leave only values we need
temp_list = [word.replace("Temperature:", '') for word in temporary_temp]
temp_list = [word.replace(" ","") for word in temp_list]
time_list = [word.replace('ï»¿',"") for word in time_list]
time_list = [word.replace(" ","") for word in time_list]

while temp_list.count('Done'):
	index = temp_list.index('Done')
	temp_list.remove('Done')
	time_list.pop(index)

temp_list = [float(item) for item in temp_list]
time_list = [parse(item) for item in time_list]

# plot the scatter plot
plt.scatter(time_list,temp_list)
plt.title("Temperature vs Time")
plt.show()

# export the new data we used to a csv file that is formatted correctly
adjusted_data= {'time':time_list,'temp':temp_list}
exported_data = pd.DataFrame(data= adjusted_data)
exported_data.to_csv('P=9,I=1,D=3.csv', index= False)
print(time_list)