def amicable(x):
	total = 0
	count = 2
	while count != x:
		divisors = []
		divisors2 = []
		for i in range(1,count/2+1):
			if count % i == 0:
				divisors.append(i)
		s = sum(divisors)
		for i in range(1,s/2+1):
			if s % i == 0:
				divisors2.append(i)
		u = sum(divisors2)
		if u == count and u != s:
			total += count
		count += 1
	return total

print amicable(10000)



