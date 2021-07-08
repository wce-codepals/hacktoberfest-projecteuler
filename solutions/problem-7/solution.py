def is_prime(num):
    """Returns True if the number is prime
    else False."""
    if num == 0 or num == 1:
        return False
    for x in range(2, num):
        if num % x == 0:
            return False
    else:
        return True

i=0
n=-1
while i < 10001:
    n +=1
    prime = is_prime(n)
    if prime:
        i += 1

print(i, n)
