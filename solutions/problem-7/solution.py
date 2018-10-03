primes = [2]
n = 3
while len(primes) < 10001:
    for prime in primes:
        if n % prime == 0:
            break
    else:
        primes.append(n)
    n += 2
print(primes[-1])
