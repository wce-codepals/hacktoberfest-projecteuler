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
count=0
while(True):
	temp = is_prime(num)
	if temp==True:
		count=count+1
		if count==10001:
			print(num)
			break
	num=num+1