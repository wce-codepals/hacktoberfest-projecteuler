# Project Euler: Problem 48
# URL: https://projecteuler.net/problem=48
# Author: https://github.com/Refisio


# place our solution in a function so that it can be used for any series
def fourtyeight(number):
    # our total, which will store the final number
    total = 0

    # for x in the range of the specified number, add its self-square to our total
    for x in range(1, number):
        total += x ** x

    # return the last 10 digits of the series as a string
    return str(total)[-10:]


print(fourtyeight(1000))
