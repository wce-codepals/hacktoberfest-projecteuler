def factorial(n):
    res = 1;
    for i in range (1,n+1):
        res = res * i
    return res
n = int(input())
print(sum(list(map(int,str(factorial(n))))))
