def sum_multiples(number, upper_bound):
    qt_divisors = int(upper_bound / number)
    s = number * (qt_divisors * (qt_divisors + 1)) / 2
    return int(s)


answer = sum_multiples(3, 999) + \
         sum_multiples(5, 999) - \
         sum_multiples(15, 999)

print(answer)