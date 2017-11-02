"""
Solving Longest Collatz sequence problem
https://projecteuler.net/problem=14
"""


def chain_size(start):
    n = start
    count = 1
    while n > 1:
        count += 1
        n = n // 2 if n % 2 == 0 else 3*n + 1
    return count


def collatz(startmax):
    size = 0
    for start in range(startmax):
        new_size = chain_size(start)
        if new_size > size:
            size = new_size
            nstart = start
    return nstart, size


if __name__ == '__main__':
    nstart, size = collatz(1000000 - 1) 
    print(nstart)

