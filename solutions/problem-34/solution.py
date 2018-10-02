# computes factorial of a number
def factorial(n):
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result
 
F = [factorial(i) for i in range(0,10,1)]
 
S = 0
for i in range(3,2540161,1):
	digits = [int(x) for x in str(i)]	# stores digits of number
	D = sum([F[j] for j in digits])		# computes the sum of factorials of all digits
	if D == i: S += D
 
print "Result is %s." % (S)
