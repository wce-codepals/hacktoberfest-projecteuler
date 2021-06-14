import math
#function to append prime numbers till upper bound by SieveOfEratosthenes
def SieveOfEratosthenes(n): 
  prime = [True for i in range(n+1)] 
  p = 2
  while (p * p <= n): 
    if (prime[p] == True): 
      for i in range(p * p, n+1, p): 
        prime[i] = False
    p += 1
  for p in range(2, n): 
    if prime[p]: 
      lst.append(p)
N=10001 #prime number of index n 
#calculation of upper bound of n`th prime
upperlimit=math.ceil(N*math.log(N)+N*math.log(math.log(N)))
lst=[]
SieveOfEratosthenes(upperlimit)
print(lst[N-1])
