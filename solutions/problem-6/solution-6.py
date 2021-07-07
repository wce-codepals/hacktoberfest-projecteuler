n=100                       #initializing the value of n by 100
sum1=sum2=0                 
for i in range(n):          #loop to calculate sum of squares
    sum1=sum1+((i+1)**2)
for i in range(n):          #loop to calculate square of sum
    sum2=sum2+(i+1)
sum2=sum2**2
print(sum2-sum1)            #taking difference of two
