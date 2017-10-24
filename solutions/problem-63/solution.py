#This is solution for problem 63 written in Python.
# The below code is the simplest exectution for the given problem.
#Read comments beside code to understand better.
#INPUT: Interger N
#OUTPUT: Line seperated numbers satisfying the problem condition.

#NOTE: THIS CODE MIGHT CREATE PROBLEMS WHILE IMPLEMENTING IN PYTHON 2, DUE TO LIMITED RANGE OF ISLICE().
#HENCE, FIXING MEMORY ERROR IN THIS CASE WILL BE APPRECIATED.

from itertools import islice, count

#input number from user
N=input()

storing lowerbound and upperbound in low and high
low=pow(10,N-1)
high=pow(10,N)

#running loop for all numbers upto upperbound, 
#and storing their n-th power in temp,
#if temp falls in my range of examination, print temp.
for index in islice(count(1),high/N):
    temp=pow(index,N)
    if temp/high==0 and (temp/low)!=0:
        print temp
