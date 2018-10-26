f= 1
sum = 0
for i in range(1,101):
    f = f * i
while(f > 0):
    r = f % 10
    f = f / 10
    f = int(f)
    sum = sum + r
print(sum)