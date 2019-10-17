import math

def rotate(data):
    g = []
    g.append(int(data))
    h = ''
    for _ in range(len(data)-1):
        h =  data[1:] + data[0]
        h = int(h)
        g.append(h)
        data = str(g[-1])
    for i in reversed(range(len(g))):
        if str(g[i]).__len__() != str(g[0]).__len__():
            del g[i]
    return g

def isprime(data):
    for i in range(2, int(math.sqrt(data))+1):
        if data%i == 0:
            return 0
    return 1

count = 1
for i in range(3,1000000):
    flag = False
    g = rotate(str(i))
    if g.__len__() != str(i).__len__():
        continue
    for p in g:
        if isprime(p) == 0:
            flag = True
            break
    if flag == False:
        count += 1
        print(i)
    else:
        continue

print(count)
