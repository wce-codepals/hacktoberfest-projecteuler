def is_prime(number):
    for i in range(2,int(number/2+1)):
        if(number%i==0):
            return False
    else:
        return number

def sum_of_primes(num):
    value=0
    for i in range(2,num):
        value+=is_prime(i)
    return value

print(sum_of_primes(10))

#replace 10 by 2 million (2000000)