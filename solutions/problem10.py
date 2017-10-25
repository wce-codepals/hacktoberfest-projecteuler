primes = [True for i in range(2000001)]

def sieve():
	primes[0], primes[1] = False, False
	for i in range(2, 2000001):
		if(primes[i]):
			for j in range(2*i,2000001,i):
				primes[j]=False

ans=0
sieve()
for i in range(1,2000001):
	if(primes[i]):		
		ans = ans+i
print(ans)
