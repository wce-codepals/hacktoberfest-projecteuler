n = 100
f = 1
for i in range (1, n+1) :
    f = f * i
sum = 0
while (f > 0):
    rem = f % 10
    sum = sum + rem
    f = f // 10

print sum
