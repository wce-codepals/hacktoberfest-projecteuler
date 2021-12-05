from operator import mul

with open('008.txt') as frame:
    a = frame.readline()

n = 13
c = 1
for i in range(1, len(a)-n):
    b=1
    for j in a[i:i+n]:
        b *= int(j)
    # b = reduce(mul, map(int, a[i:i+5]))
    if b > c:
        c = b
print(c)
