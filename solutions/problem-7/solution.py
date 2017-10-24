import sys
from math import sqrt
from itertools import count, islice


def is_prime(n):
    """Returns boolean value if number is prime."""
    return n > 1 and all(n % i for i in islice(count(2), int(sqrt(n)-1)))


def nth_prime(n):
    """Returns nth prime number for value of n."""
    num = 0
    count = 0
    while (count < n):
        if (is_prime(num)):
            count += 1
        num += 1
    print(num - 1)


nth_prime(int(sys.argv[1]))
