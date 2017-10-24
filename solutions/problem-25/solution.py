num1 = 0
num2 = 1
num = 1
while num1 + num2 < 1000:
    num1 = num1 + num2
    if num1 + num2 > 1000:
        num = num + 1
        continue
    num2 = num1 + num2
    num = num + 2
print (num)
