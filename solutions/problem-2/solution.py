cache = {}  
def fiba(n):  
     cache[n] = cache.get(n, 0) or (n <= 1 and 1 or fiba(n-1) + fiba(n-2))  
     return cache[n]  
n = 0  
x = 0  
while fiba(x) <= 4000000:  
       if not fiba(x) % 2: n = n + fiba(x)  
       x=x+1  
print(n)
