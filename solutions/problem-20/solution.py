
import math

x = 100
fact = math.factorial(x)

sum_fact = sum(int(digit) for digit in str(fact))

print(sum_fact)
