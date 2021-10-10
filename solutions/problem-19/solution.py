import datetime

# Solve using brute force.
def solve():
	l = [1 for y in range(1901, 2001) for m in range(1, 13) if datetime.date(y, m, 1).weekday() == 6]
	return sum(l)

if __name__ == "__main__":
	sol = solve()
	print(solve())
