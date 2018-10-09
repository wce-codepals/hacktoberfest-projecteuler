def fact(num):
	mult=1
	for x in range(1,num+1):
		mult=mult*x
	return mult

fact_num=fact(10000)
temp=fact_num
sum=0
for x in range(len(str(fact_num))):
	while(temp>0):
		t=temp%10
		sum=sum+t
		temp=temp//10
print(sum)
