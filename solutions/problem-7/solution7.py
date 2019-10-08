def primeFactorDecomp (n):
  #given a number n, finds its factorial decomposition and saves it in a dictionary where key is base and value is power.
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
	return factors

i=0
num=1
while i<10001:
#Loops until 10k
	num+=1
	decom=primeFactorDecomp(num)
  #a prime number would have only 1 value in its factorial decomposition, with power 1.
	if len(decom)==1 and list(decom.values())[0]==1:
		i+=1
		#print(f" the {i}th prime is {num}")
		
print (num)
