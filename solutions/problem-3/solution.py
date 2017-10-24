#Add Python solution to problem-3
from math import sqrt
def isprime(n):
	"""this function will check that
	divisor is prime or not"""
	f=1
	for i in range(2,int(sqrt(n))+1):
		if n%i==0:
			f=0
			break
	if f==0:
		return 0
	else:
		return 1
x=600851475143
l=[]
for j in range(2,int(sqrt(x))+1):
	"""this function will check that j(iterator)
	divides x(target number) and simultaneously check 
	it is prime or not. If it is divisor and prime both then
	it is stored in list l"""
	if x%j==0 and isprime(j):
		l.append(j)
#Here we sort the list so first element after sort/
#	will be greatest prime divisor
		
l.sort(reverse=True)
print(l[0])#here is output
		
