#!/usr/bin/env python

d = {}
isPrime = [True]*5000
primes = []
for i in xrange(2, len(isPrime)):
    if isPrime[i]:
        for j in xrange(2*i, len(isPrime), i):
            isPrime[j]=False
for i in xrange(2, len(isPrime)):
    if isPrime[i]:
        primes.append(i)

def primep(k,n):
    if (k,n) in d: return d[(k,n)]
    if k >= len(primes) or primes[k]>n: return 0
    if primes[k]==n: return 1
    val = primep(k, n-primes[k]) + primep(k+1,n)
    d[(k,n)] = val
    return val

n = 10
ways = 5
while ways <= 5000:
    n += 1
    ways = primep(0,n)
print n