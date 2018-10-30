def find_even_fibonacci(num):
    a, b = 0, 1
    sum = 0
    while b < num:
        a, b = b, a + b
        if b % 2 == 0:
            sum += b
    return sum


print(find_even_fibonacci(4))
