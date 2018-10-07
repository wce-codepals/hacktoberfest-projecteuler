# Note:
# The bounds were decided after some mathematical analysis.
# Code is golfed.

print(sum([x for x in range(1000, 999999) if x == sum([int(c)**5 for c in list(str(x))])]))

# Explanation
# "x for x in range(1000, 999999)" loops through numbers from 1000 to 999999 (Read notes for bounds)
# x is added to the list only if it is equal to the sum of the 5th power of the digits
# list(str(x)) converts the number into a string first and then a list.