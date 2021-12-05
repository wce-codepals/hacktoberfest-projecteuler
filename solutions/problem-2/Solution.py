def Fibo(n):
    i=1
    j=1
    Fibo=0
    sum=0
    while(Fibo<=n):
        Fibo=i+j
        i=j
        j=Fibo
        if Fibo%2==0:
            sum=sum+Fibo
    return sum        

#test_case n=4,000,000
ans=Fibo(4000000)
print("Sum = ", ans)
