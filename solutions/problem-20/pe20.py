# sum of the digits in the number 100!
def fact(num):
    if num == 1: return 1
    else : return num * fact(num-1)
value = fact(100)
s = 0
for i in str(value):
    s += int(i)
print(s)