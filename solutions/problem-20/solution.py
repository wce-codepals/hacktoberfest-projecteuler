from math import factorial

string = str(factorial(100))

sum = 0

for i in string:
    sum += int(i)

print(sum)
