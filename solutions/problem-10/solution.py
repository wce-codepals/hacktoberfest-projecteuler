def is_prime(num):
	if num == 2 or num == 3:
		return True
	else:
		for x in range(2,num//2+1):
			if num%x == 0:
				return False
			elif x == num//2 :
				return True
		
num=2
s=0
while(num<200000):
	temp = is_prime(num)
	if temp==True:
		s=s+num
	num=num+1
print(s)
