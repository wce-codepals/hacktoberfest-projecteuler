def calc(n):
    c=0
    while n!=0:
        q=n%10
        n=n//10
        c=c+q
    return c

r=pow(2,1000)
w=calc(r)
print(w)