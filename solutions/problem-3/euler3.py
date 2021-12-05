def prime(n):   
    p = 2
    while (p*p <= n):      
        if (n % p == 0): 
            n //= p
        else: 
            p += 2 if p>2 else 1   
    print (n)
x=int(input())
a=[]
for i in range(x):
    ele=int(input())
    a.append(ele)
for j in a:
    prime(j)

