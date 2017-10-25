def collatz(n):
	if n % 2 == 0:
		return n/2
	else:
		return 3*n+1
def main():
	col = dict()

	longestnum = 1
	longestval = 1
	for i in xrange(1, 1000001):
		a = i
		t = 1
		while a != 1:
			a = collatz(a)
			t += 1
		if t > longestval:
			longestval = t
			longestnum = i

	print longestnum

if __name__ == '__main__':
	main()