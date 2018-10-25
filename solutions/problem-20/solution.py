t=int(raw_input())
i=0
while(i<t):
    n=int(raw_input())
    j=1
    k=1
    s=0
    while(j<=n):
        k=k*j
        j+=1
    while(k):
        s+=k%10
        k=k/10
    print(s)
    i+=1
        
