liste = list(range(1000))

sum_3 = 0

sum_5 = 0

sum_3ve5 = 0

for num in liste:
    if num % 3 == 0:
        sum_3 += num
    elif num % 5 == 0:
        sum_5 += 0
    elif num % 3 == 0 and num % 5 == 0:
        sum_3ve5 += 0

print(sum_3 + sum_5 - sum_3ve5)