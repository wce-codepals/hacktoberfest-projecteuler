num1 = 0
num2 = 1
num = 0
while num1 < 1000 or num2 < 1000:
    num1 = num1 + num2
    num += 1
    if num1 > 1000:
        break
    else:
        num2 = num1 + num2
        num += 1
print (num)
