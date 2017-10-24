"""
Basically, we're getting all multiples from 3 and 5, and
reducing the multiples from 15 (becase otherwise we'd double
count)
To get how many multiples exists, a simple division is enough
To get the sum, we use a ArithmeticProgression
Sum(3 * 1..QT_MULTIPLES), where we can do:
3 * SUM(1..QT_MULTIPLES)
"""


total_sum = 0
for i in range(1, 1000):
    if (i % 3 == 0 or i % 5 == 0):
        total_sum = total_sum + i
print total_sum  
