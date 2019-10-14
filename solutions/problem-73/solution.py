def compute():
	ans = 0
	stack = [(1, 3, 1, 2)]
	while len(stack) > 0:
		leftn, leftd, rightn, rightd = stack.pop()
		d = leftd + rightd
		if d <= 12000:
			n = leftn + rightn
			ans += 1
			stack.append((n, d, rightn, rightd))
			stack.append((leftn, leftd, n, d))
	return str(ans)


if __name__ == "__main__":
	print(compute())

