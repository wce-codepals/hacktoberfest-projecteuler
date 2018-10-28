def even_fibo():
    arrfib=[]
    a=0
    b=1
    for i in range(1000000): # replace 10 by 4million
        val=a+b
        arrfib.append(val)
        a=b
        b=val
    return ( sum((filter(lambda x : x%2==0 , arrfib)))  )

print(even_fibo())