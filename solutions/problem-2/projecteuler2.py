def sumeve(L):
    s, x, y = 0, 0, 2
    while y < L:
        x, y, s = y, 4*y+x, s+y

    print(s)

n=int(input())
a=[]
for i in range(n):
    ele=int(input())
    a.append(ele)
for j in a:
    sumeve(j)

    
