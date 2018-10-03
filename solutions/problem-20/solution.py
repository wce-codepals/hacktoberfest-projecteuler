n=100
pro=1
sum=0
for i in range(100):
    pro=pro*(i+1)
while(pro!=0):
    x=int(pro%10)
    pro=pro//10
    sum=sum+x
print(sum)
