"""
Solution to Project Euler #99
Read in file and compare exponents using log laws to quickly evaluate answer
"""

from math import log
expFile = open("p099_base_exp.txt","r") #file with exponent pairs

maxLine = 0 #line containing the highest exponent
curLine = 0 #current line
maxPair = [100,100]
for line in expFile:
    curLine += 1
    print(curLine)
    curPair = line.split(',')
    curPair[0] = int(curPair[0])
    curPair[1] = int(curPair[1])
    if log(curPair[0])*curPair[1] > log(maxPair[0])*maxPair[1]:
        maxLine = curLine
        maxPair = curPair

print(maxLine)
