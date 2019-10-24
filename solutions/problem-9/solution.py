a=0
b=0
c=0
ans = [a,b,c]

for b in range(1,500):
    for a in range(1,500):
        temp = 1000-a-b
        if (a*a+b*b==temp*temp):
            ans = [a,b,temp]
            
import numpy
print(numpy.prod(ans))
