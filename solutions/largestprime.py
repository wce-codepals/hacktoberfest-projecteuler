def larprime(n):
	i=2
	while i*i <=n:
		if  n%i!=0:
			i+=1
		else:
			n=n/i
	return n
print(larprime(6))
