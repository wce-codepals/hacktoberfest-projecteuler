for x in range(333):
	for y in range(x, x+333):
		if 2000 * (x + y) == 1000**2 + 2 * x * y:
			print(x*y*(1000-x-y))