
b = 3
n = 4
l = 10 ** 12
while n <= l:
    b = 3 * b + 2 * n - 2
    n = 4 * b + 3 * n - 3

print(f'Blue: {b}, Total: {n}')

# or brute force

r1 = 1000000000

r2 = 1000000000

for n in range(1, r1):
    for n2 in range(1, r2):
        if ((n / (n + n2)) * (n - 1) / (n + n2 - 1)) == 0.5:
            if n + n2 >= 1000000000000:
                print(n, n2)
                break

