"""
Basically, we're getting all multiples from 3 and 5, and
reducing the multiples from 15 (becase otherwise we'd double
count)
To get how many multiples exists, a simple division is enough
To get the sum, we use a ArithmeticProgression
Sum(3 * 1..QT_MULTIPLES), where we can do:
3 * SUM(1..QT_MULTIPLES)
"""
from __future__ import division  # imported for backward division compatibility for python2


def sum_multiples(number, upper_bound):
    qt_divisors = upper_bound // number
    return number * (qt_divisors * (qt_divisors + 1)) // 2  # operator `//` returns integer/floor value only


answer = sum_multiples(3, 999) + \
         sum_multiples(5, 999) - \
         sum_multiples(15, 999)

print(answer)
