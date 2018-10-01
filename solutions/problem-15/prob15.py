a = 1
b = 1
c = 1
for i in range(1, 11):
    a = a * i
for i in range(21, 40, 2):
    b = b * i
c = 2 ** 10

ans = (c * b)/a
print (ans)