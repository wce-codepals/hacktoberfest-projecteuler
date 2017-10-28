def factorial(n):return reduce(lambda x,y:x*y,[1]+range(1,n+1))
sum = 0
for i in str(factorial(100)):
	sum = sum + int(i)
print sum