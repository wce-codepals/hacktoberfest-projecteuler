import numpy
n=int(input())
a1=1
sum=1

for i in range (2,n+1):
    a2=0
    while(a1>0):
        a2=a2+(a1%10)
        a1=int(a1/10)

    sum=sum+a2
    a1=sum
print(sum)
