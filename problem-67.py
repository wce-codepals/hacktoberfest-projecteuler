#!/usr/bin/env python
import sys
file=open(sys.argv[1],'r')		#opens file
textfile=file.read().splitlines()	#reads lines from file without \n break line character, and converts into list
triangle=[]
count_lines=0
for line in textfile:
	triangle.append(line.split(" "))	#for each line in textfile splits each line to list of numbers
	count_lines+=1

triangle=[map(int,x) for x in triangle]

pos=0
_sum=0
for i,item in enumerate(triangle):
	if i==0: _sum=triangle[0][0]
	elif triangle[i][pos]>triangle[i][pos+1]: 
		_sum=_sum+triangle[i][pos]
	else:
		_sum=_sum+triangle[i][pos+1]
		pos=pos+1
print "maximum route has sum:",_sum