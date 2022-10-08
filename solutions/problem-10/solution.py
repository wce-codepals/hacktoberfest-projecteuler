def SumPrime(number):
    prime = []
    for a in range(1,number+1):
        l = []
        for i in range(1, a+1):
            (l).append(a % i)
        r = (l.count(0))
        if r == 2:
            prime.append(a)
    return sum(prime)

