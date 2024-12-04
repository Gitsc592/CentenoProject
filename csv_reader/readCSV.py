########################################################
## Filename : readCSV.py
## Author : Sed Centeno
## Date : 11/29/2024
##
## Description :
## Reads Adafruit I/O csv data and computes the 
## minimum, maximum and average of the data.
##
## Arguments :
## Filename (./feed_data.csv)
##
## Example Invocation :
## python3 ./readCSV.py ./feed_data.csv
#########################################################

import sys

csv_file = open(sys.argv[1])
csv_lines = csv_file.readlines()
sum = 0
max = float("-inf")
min = float("inf")

for i in range(len(csv_lines) - 1):
    columns = csv_lines[i + 1].split(",")
    data = eval(columns[1])
    sum = sum + data
    if data > max:
        max = data
    if data < min:
        min = data


sum = sum/(len(csv_lines) - 1)
print("Average =",sum)
print("Max =", max)
print("Min =", min)
