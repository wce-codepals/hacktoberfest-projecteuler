def fact(x):
    if (x==0):
        return 1
    y = x
    for i in range(1, x):
        y*=i
    return y

result = 0
for i in range(10, 2540161):
    sof = 0
    number = 1
    while(number > 0):
        d = int(number%10)
        number/=10
        sof += fact(d)
    
    if (sof==i):
        result += i

print(result)
# Takes about 433*5 ms