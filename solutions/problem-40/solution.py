q = [9*(x+1) * pow(10, x) for x in range(100)]

def d(n):
	i=0
	while n>q[i]: n-= q[i]; i+= 1
	L, d = divmod((n-1), i+1)
	return int(str(pow(10, i)+L)[d])

n = input("Enter some indicies, separated by a space? ")
m = 1
for ci in map(int, n.split()):
    m*= d(ci)
print ("product =", m)

'''
Sample Input:
1 10 100 1000 10000 100000 1000000
Sample output:
product = 210
'''
