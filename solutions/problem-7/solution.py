#http://code.jasonbhill.com/python/project-euler-problem-7/ 
import time
 
def fast_nth_prime(n, limit=125000):
    if limit % 2 != 0: limit += 1
    primes = [True] * limit
    primes[0],primes[1] = [None] * 2
    count = 0 # how many primes have we found?
    for ind,val in enumerate(primes):
        if val is True:
            # sieve out non-primes by multiples of known primes
            primes[ind*2::ind] = [False] * (((limit - 1)//ind) - 1)
            count += 1
        if count == n: return ind
    return False
 
start = time.time()
prime = fast_nth_prime(10001)
elapsed = (time.time() - start)
 
print "found %s in %s seconds." % (prime,elapsed)
