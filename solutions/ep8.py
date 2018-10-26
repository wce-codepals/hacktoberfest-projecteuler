#!/bin/python3

import sys
import operator

import functools

t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')#standard input
    n,k = [int(n),int(k)]
    num = input().strip()
    l=[int(z) for z in str(num)] #input the array
    for j in range(len(l)):
        q=l[j:j+k] #take only the specified amount of elements
        p=functools.reduce(lambda x,y: x*y, q) #use lambda function to calculate the product
        if len(q)!=k: #till sufficent elements remain
            break
        if j==0:
            a1=p
        else:
            if p>a1: #find the max product
                a1=p
    print(a1,end="\n")