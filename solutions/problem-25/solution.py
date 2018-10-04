a = b = 1
c = 2
while len(str(b)) < 1000:
	a, b = b, a+b
	c += 1
print(c)
