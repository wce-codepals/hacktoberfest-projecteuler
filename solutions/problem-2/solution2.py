a = 0
b = 1
total = 0
while True:
	c = a + b
	a = b
	b = c
	if c < 4000000:
		if c % 2 == 0:
			total = total + c
		else
			continue
	else
		break
print(total)
