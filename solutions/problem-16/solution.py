import math

number = int(math.pow(2, 1000))

#construt a tuple of digits using the number above
digits = (int(x) for x in str(number))
print(sum(digits))
