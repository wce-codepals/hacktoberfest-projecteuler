# Project Euler: Problem 20
# URL: https://projecteuler.net/problem=20
# Author: https://github.com/Refisio


def factorial(num):
    start_number = 1
    final_number = 0
    for i in reversed(range(num + 1)):
        if i != 0:
            start_number *= i
    for i in str(start_number):
        final_number += int(i)
    return final_number


print(factorial(100))
