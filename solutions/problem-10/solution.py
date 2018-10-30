def is_prime(number):
    for i in range(2, int(number**(1/2))+1):
        if number % i == 0:
            return False
    return number


def sum_of_prime(number):
    sum = 0
    for i in range(2, number):
        sum += is_prime(i)
    return sum


number = int(input())
print(sum_of_prime(number))