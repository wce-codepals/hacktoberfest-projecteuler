# import time module
import time

# time at the start of program execution
start = time.time()


# Sieve of Erotosthenes
# One of the best algorithm to generate prime numbers
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
def sieve(n):
    is_prime = [True]*n
    is_prime[0] = False
    is_prime[1] = False
    is_prime[2] = True
    # even numbers except 2 have been eliminated
    for i in xrange(3, int(n**0.5+1), 2):
        index = i*2
        while index < n:
            is_prime[index] = False
            index = index+i
    prime = [2]
    for i in xrange(3, n, 2):
        if is_prime[i]:
            prime.append(i)
    return prime

# prime numbers upto 1 million
primes = sieve(1000000)

# length of the consecutive prime sum
length = 0

# value of the consecutive prime sum
largest = 0

# max value of the j variable(second for loop)
lastj = len(primes)

# two for loops
for i in xrange(len(primes)):
    for j in xrange(i+length, lastj):
        sol = sum(primes[i:j])
        if sol < 1000000:
            if sol in primes:
                length = j-i
                largest = sol
        else:
            lastj = j+1
            break

# printing the requried solution
print largest

# time at the end of program execution
end = time.time()

# total time for program execution
print end - start