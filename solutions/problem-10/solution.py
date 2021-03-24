#
# Solution to Project Euler 10
# written in python by Elle
# https://github.com/PronElle
#


def Eratosthenes(n):
    """implements Eratosthnes sieve to sum all primes below n"""
    # create a bool array tracing primes
    # p is prime if prime[p] = True
    prime = [True] * (n + 1)
    prime[0] = prime[1] = False
    p = 2

    while (p * p <= n):
        if (prime[p]):
            # update all multiples of p
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 1

    return sum([p for p in range(n+1) if prime[p]])


if __name__ == '__main__':
    print(Eratosthenes(1999999))
