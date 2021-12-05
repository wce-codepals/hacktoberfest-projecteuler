import math

def is_abundant(number):
    divisors = find_divisors(number)
    return True if sum(find_divisors(number))>number else False

def find_divisors(number):
    divisors = []
    for i in range(1, number):
            if number % i == 0:
                divisors.append(i)
    return divisors

def is_abundant_sum(number, abundants):
    for i in abundants:
        if i > number:
            return False
        if (number - i) in abundants:
            return True
    return False

if __name__ == '__main__':
    abundants = [i for i in range(28123+1) if is_abundant(i)]
    print(sum(i for i in range(28123+1) if not is_abundant_sum(i, abundants)))

