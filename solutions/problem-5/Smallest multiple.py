import math

# In short we have to find the lcm

def Smallest_multiple(array):
    lcm=array[0]
    for i in array[1:]:
        lcm = int( lcm*i/math.gcd(lcm,i) )    # gcd is greatest common divisor
    return lcm

print(Smallest_multiple(range(1,11)))

