"""
Find the sum of all the primes below two million.

https://projecteuler.net/problem=10
"""
from __future__ import print_function
from math import sqrt, floor

def solve(n):
    stop = floor(sqrt(n))

    sum = 0
    multiples = [2]

    for i in range(2, n+1):
        candidate = True
        if i == 2:
            sum += 2
            continue

        for base in multiples:
            if i % base == 0:
                candidate = False
                break

        if candidate:
            if i not in multiples and i <= stop:
                multiples.append(i)
            sum += i

    return sum

if __name__ == "__main__":
    print("sum of primes up to 1 million:", solve(1000000)) # 37550402023
    print("sum of primes up to 2 million:", solve(2000000))
