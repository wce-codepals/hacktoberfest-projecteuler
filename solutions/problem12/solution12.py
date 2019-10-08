def divisorsThroughPrimeFactorDecomps (n):
	factors={}
	i=2
	while n>1:
		if n%i==0:
			if i in factors.keys():
				factors[i]+=1
			else:
				factors[i]=1
			n=n/i
		else:
			i+=1
	divisorAmount=1
	for k,v in factors.items():
		divisorAmount*=(v+1)
	#print(factors)
	return divisorAmount
	

n=1
trianglen=1
while (divisorsThroughPrimeFactorDecomps(trianglen))<500:
	n+=1
	trianglen+=n

print (trianglen)
