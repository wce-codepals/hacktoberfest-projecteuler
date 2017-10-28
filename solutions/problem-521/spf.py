def smpf(num):
    i=1
    while True:
        i+=1
        if num%i==0:
            return i

def S(n):
    sum=0
    for item in range(2,n+1):
        sum+=smpf(item)
    return sum


# print(S(10**12)%10**9)
