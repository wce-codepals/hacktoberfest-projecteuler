# sum of the digits of the number 2^1000
import math
value = int(math.pow(2,1000))
s = 0
for i in str(value):
    s += int(i)
print(s)