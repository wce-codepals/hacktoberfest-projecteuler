import math


# We do a straightforward computation thanks to Python's built-in arbitrary precision integer type.
def compute():
	n = math.factorial(100)
	ans = sum(int(c) for c in str(n))
	return str(ans)


if __name__ == "__main__":
	print(compute())