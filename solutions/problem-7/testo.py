import sys
find_num = int(sys.argv[1]) #assumes the requested number is greater than 0
num = 2
primes = [num]
while(len(primes) < find_num):
    num+=1
    is_prime = True
    """Check if divisible by previous prime numbers"""
    for n in primes:
        if num % n == 0:
            is_prime = False
            break
    if is_prime:
        """Keep looking until half the current number"""
        i = primes[-1]
        while i < num//2:
            if num % i == 0:
                is_prime = False
                break
            i+=1
        if is_prime:
            primes.append(num)
print(primes[-1])
