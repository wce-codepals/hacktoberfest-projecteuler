n=input("enter the number")
fact=1
sum=0
for i in range(1,n):
	fact=fact*i
print(fact)
while(fact > 0):
	p=fact%10
	sum=sum+p
	fact=fact/10
print(sum)
