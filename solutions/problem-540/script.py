from fractions import gcd

def prerequisites(a, b, c, n):
    if a < 0 or b < 0 or c <0: 
        return False 
    
    if a*a + b*b != c*c:
        return False

    if gcd(a,b) != 1 and gcd(a,c)and gcd(b,c):
        return False
    
    if a < b and b < c  and c <= n: 
        print a, b, c
        return True
        

def counting_primitive(n):
    result = 0
    
    for a in range(1,n):
        for b in range(1,n):
            for c in range(1,n):
                if(prerequisites(a,b,c,n)):
                    result += 1
    return result
    
counting_primitive(20)

