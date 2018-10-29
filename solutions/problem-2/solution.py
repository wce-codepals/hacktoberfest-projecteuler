def even_fibo():
    arrfib=[]
    a=0
    b=1
    for i in range(4000000):
        val=a+b
        arrfib.append(val) #this list stores all fibo numbers
        a=b
        b=val
    return ( sum((filter(lambda x : x%2==0 , arrfib)))  ) #here we return the sum of only the even numbers of the fibo series

print(even_fibo())
