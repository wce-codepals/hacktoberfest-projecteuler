import math

def sieve(n):
	is_prime = [True]*n
	is_prime[0] = False
	is_prime[1] = False

	for i in range(2,int(math.sqrt(n)+1)):
		index = i*2
		while index < n:
			is_prime[index] = False
			index += i
	
	prime = []

	for i in range(n):
		if is_prime[i] == True:
			prime.append(i)
	return prime

ans=[]
s=0
ans=sieve(2000000)
for x in ans:
	s = s+x;
print(s)
