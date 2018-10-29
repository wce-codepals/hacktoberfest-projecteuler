number = 2
c = 1
p = 0
sum = 0
while number < 2000000:
    i = number -1
    while i > 1:
        if number % i == 0: break
        i -= 1
        c += 1
    else:
        sum += number
        p += 1
    number += 1
print(sum)
