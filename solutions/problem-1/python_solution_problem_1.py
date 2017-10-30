#to print the sum of multiples of 3 and 5 below 1000

a=1000
b=[]
c=[]
for i in range(a):
	if i%3==0:
		b.append(i)
for i in range(a):
	if i%5==0:
		c.append(i)
m=b+c
w=set(m)

print("Sum is:",sum(w))


