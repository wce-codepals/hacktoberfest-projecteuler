import math


# We do a straightforward computation thanks to Python's built-in arbitrary precision integer type.
def sum_of_num():
	num = math.factorial(100)
	ans = sum(int(c) for c in str(num))
	return str(ans)


if __name__ == "__main__":
	print(sum_of_num())
