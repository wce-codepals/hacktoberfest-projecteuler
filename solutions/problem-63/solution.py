LIMIT = 22
count = 0
for i in xrange(1, LIMIT):
	for digit in xrange(2, 10):
		if len(str(digit**i)) == i: count +=1
print(count+1) # adding 1**1