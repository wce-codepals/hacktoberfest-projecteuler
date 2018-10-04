
"""
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
"""

def is_prime(num):
    counter = num - 1
    while counter >= 2:
        if num % counter == 0:
            return False
        counter -= 1
    return True


num = 2L  # first prime number
prime_sum = 0L
max_num = 2000000L
while num <= max_num:
    print(num)
    if is_prime(num):
        prime_sum += num
    num += 1

print("The sum of all primes below 2,000,000 is {}".format(prime_sum))  # 142,913,828,922
