from fractions import gcd
 
def euler_totien(n):
    result = 0    
    
    for a in range(1,n):
        if(gcd(a,n) == 1):
            result += 1
            
    return result
   
euler_totien(10)

