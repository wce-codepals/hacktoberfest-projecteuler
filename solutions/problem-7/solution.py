def isprime(n):                   #checks whether number n is prime or not
	if n == 1:
		return False
	i=2
	while i*i <= n:       
		if n % i == 0:
			return False                #in case not prime returns false
		i+=1
	return True                     #in case prime returns true



x = 10001
count = 0
num = 2
prime_list=[]
while count < x:
     if isprime(num):             #if true is returned enters if statement
       	prime_list.append(num)    #appends number to the list
        count = count + 1         #increases counter
     num = num + 1

print(prime_list[10000])          #for number at 10001 position prints number at 10000 as the index starts from 0
