#This is the solution for problem 11 written in python language. 
#For convenience, check for comments written beside the codes. 
#Input format: Enter 20 lines of space-seperated integers, each line depicting one row, and every space seperated number depicting different columns.
#Output: The greatest product in the given grid.
#Constraints: Valid only for 20X20 grid. To make it flexi, update 20 by a variable (which will be entered by the user).


import sys

grid = [] 

#Input the grid from user
for _ in xrange(20):
    temp = map(int,raw_input().strip().split(' '))
    grid.append(temp)

#making four lists for storing products of numbers evaluated
#horizontally, vertically, diagonally towards right, and diagonally towards left. 
#Finally storing all the max values of lists in high.
#NOTE: Alternate way is to make a single list for all products, but it makes storing and fetching a value more complicated.
prod_hr=[]
prod_diar=[]
prod_dial=[]
prod_vert=[]
high=[]

#evaluating products of numbers horizontally
for row in range(len(grid)):
    for column in range(len(grid)-3):
        producth=(grid[row][column])*(grid[row][column+1])*(grid[row][column+2])*(grid[row][column+3])
        prod_hr.append(producth)
high.append(max(prod_hr))

#evaluating products of numbers vertically
for row in range(len(grid)-3):
    for column in range(len(grid)):
        productv=(grid[row][column])*(grid[row+1][column])*(grid[row+2][column])*(grid[row+3][column])
        prod_vert.append(productv)
high.append(max(prod_vert))

#evaluating products of numbers diagonally towards right.
for row in range(len(grid)-3):
    for column in range(len(grid)-3):
        productdr=(grid[row][column])*(grid[row+1][column+1])*(grid[row+2][column+2])*(grid[row+3][column+3])
        prod_diar.append(productdr)
high.append(max(prod_diar))

#evaluating products of numbers diagonally towards left.
for row in range(3,len(grid)):
    for column in range(0,len(grid)-3):
        productdl=(grid[row][column])*(grid[row-1][column+1])*(grid[row-2][column+2])*(grid[row-3][column+3])
        prod_dial.append(productdl)
high.append(max(prod_dial))

#Now, high has all max values of product lists, precisely- 4 values.
#Printing the max value of high will result in the answer.
print max(high)

#This is probably the most user-friendly way of implementing the code. 
#Other solutions, like using a single list for all products might make understanding the code harder for new coders. 
#However, suggestions are most welcome!
