# triangular number with over 500 divisors
n = 1
primes = [2]
num = 3
while (len(primes) != 500):
    status = 1
    for i in primes:
        if num % i == 0:
            status = 0
            break
    if status:
        primes.append(num)
    num += 1
while(1):
    triangular = int(n*(n+1)/2)
    divisors = 1
    prime = [i for i in primes if i < triangular]
    temp = triangular
    for i in prime:
        count = 0
        while temp%i == 0:
            count += 1
            temp = int(temp/i)
        if count>0:
            divisors *= (count+1)
    if divisors > 500:
        print(triangular)
        break
    n += 1