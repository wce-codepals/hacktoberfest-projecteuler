#!/bin/python3

import sys
def largest_prime_factor(n):
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
    return n

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(largest_prime_factor(n))
