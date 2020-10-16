"""
Summation of primes

Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
"""


def sum_primes(n):
    result_sum = 0
    sieve = [True] * (n + 1)
    for p in range(2, n):
        if sieve[p]:
            result_sum += p
            for i in range(p * p, n, p):
                sieve[i] = False
    return result_sum


if __name__ == "__main__":
    N = 2000000
    print(f"Sum of all the primes below two million: {sum_primes(N)}")
