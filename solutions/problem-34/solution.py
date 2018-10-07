# Note:
# The bounds were decided after some mathematical analysis.
# Code is golfed.
from math import factorial as fact
print(sum([x for x in range(10, 2540160) if x == sum([fact(int(c)) for c in list(str(x))])]))

# Explanation
# "x for x in range(1000, 999999)" loops through numbers from 1000 to 999999 (Read notes for bounds)
# x is added to the list only if it is equal to the sum of the 5th power of the digits
# list(str(x)) converts the number into a string first and then a list.