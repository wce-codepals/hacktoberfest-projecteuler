#!/usr/bin/env python
max_possible = 6*(9**5)
max_sum = 0
for num in xrange(2, max_possible):
	sum_of_digits = 0
	digits = map(int, str(num))
	for digit in digits:
		sum_of_digits += digit**5
	if sum_of_digits == num:
		max_sum += num
print max_sum