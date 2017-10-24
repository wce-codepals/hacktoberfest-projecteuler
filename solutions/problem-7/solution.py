LIMIT = 200000
not_prime = set()
primes = []

for i in range(2, LIMIT+1):
	if i in not_prime: continue
	for x in range(i*2, LIMIT+1, i):
		not_prime.add(x)
	primes.append(i)
print primes[10001-1] # lists are 0-indexed