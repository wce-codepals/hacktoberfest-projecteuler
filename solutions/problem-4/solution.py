def is_Palindrome(n):
	temp = n
	rev = 0
	while(n > 0):
		dig = n % 10
		rev = rev * 10 + dig
		n = n // 10
	if(temp==rev):
		return True
	else:
		return False

def main():
	num1, num2, max_pal = 1, 1, 1
	for i in xrange(101, 1000):
		for j in xrange(101, 1000):
			num = i * j
			if is_Palindrome(num):
				if max_pal < num:
					num1, num2, max_pal = i, j, num
	print num1, num2, max_pal

if __name__ == '__main__':
	main()