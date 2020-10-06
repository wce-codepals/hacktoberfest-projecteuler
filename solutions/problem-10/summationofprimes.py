import math
def isPrime(a):
    if a<2:
        return False
    else:
        for i in range(2,int(math.sqrt(a)+1)):    
            if a % i ==0:
                return False
        return True

sum = 0
for j in range(2,2000000):
    if isPrime(j):
        sum+=j

print(sum)


