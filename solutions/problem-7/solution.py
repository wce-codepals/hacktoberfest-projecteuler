def primes(n):
    primes = [2]
    evaluated = 3
    while len(primes) < n:
        if all(evaluated % prime != 0 for prime in primes):
            primes.append(evaluated)
        evaluated += 2
    return primes[-1]