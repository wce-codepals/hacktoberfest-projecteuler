"""
In this, all the multiples of 3 and 5 upto 1000 are summed up and the result is printed.
"""
sum = 0
for i in range(1000) :
    if i % 3 == 0 or i % 5 == 0 :
	sum = sum + i
print(sum)
