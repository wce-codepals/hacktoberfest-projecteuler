def sumPrimes(n):
    """
    Implement Sieve of Eratosthenes
    Credit to https://programmingpraxis.files.wordpress.com/2012/09/primenumbers.pdf
    """
    sum, sieve = 0, [True] * n
    for p in range(2, n):
        if sieve[p]:
            sum += p
            for i in range(p*p, n, p):
                sieve[i] = False
    return sum

print sumPrimes(2000000)