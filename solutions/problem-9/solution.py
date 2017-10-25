def main():
	for a in xrange(1, 998):
		for b in xrange(1, 1000 - a - 1):
			c = 1000 - a - b
			if a**2 + b**2 == c**2:
				print a*b*c
				exit()

if __name__ == '__main__':
	main()