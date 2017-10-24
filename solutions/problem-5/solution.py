from math import *
def is_prime(num):
	"""Returns True if the number is prime
	else False."""
	if num == 0 or num == 1:
		return False
	for x in range(2, num):
		if num % x == 0:
			return False
	else:
		return True

def main():
	max_divisor = 20
	result = 1
	prime_nos = prime_nos = filter(is_prime, range(1, 20))
	for prime in prime_nos:
		a = floor(log(max_divisor)/log(prime))
		result = result * pow(prime, a)
	print result

if __name__ == '__main__':
	main()
