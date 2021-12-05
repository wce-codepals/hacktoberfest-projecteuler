def factorial(fact_num = 100):
    f = 1

    if fact_num < 0:
       return -1
    elif fact_num == 0:
       return 1
    else:
       for i in range(1, fact_num + 1):
           f = f*i
       return f


def sum_of_digits(n):
    sum = 0
    while (n > 0):
        sum += n%10
        n = n//10

    return sum

print(sum_of_digits(factorial(100)))