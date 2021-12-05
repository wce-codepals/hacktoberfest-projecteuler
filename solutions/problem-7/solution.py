import math

def find_nth_prime(nth_number):
    def is_prime(num):
        if num == 0 or num == 1:
            return False
        for x in range(2, num):
            if num % x == 0:
                return False
        else:
            return True
    primes = []
    
    largest_limit= nth_number * math.log( nth_number * math.log(nth_number))
    largest_limit=round(largest_limit)
    for i in range(largest_limit):
      if is_prime(i):
            primes.append(i)
      if len(primes) == nth_number:
            break
    print("The {}th prime number is: ".format(nth_number) + str(primes[nth_number-1]))

