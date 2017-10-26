
import eulerlib, sys
if sys.version_info.major == 2:
	range = xrange


def compute():
	solution = 0
	checkPrime = eulerlib.list_primality(999999)
	primes = eulerlib.list_primes(999999)
	consecutive = 0
	for i in range(len(primes)):
		total = primes[i]
		consec = 1
		for j in range(i + 1, len(primes)):
			total += primes[j]
			consec += 1
			if total >= len(checkPrime):
				break
			if checkPrime[total] and consec > consecutive:
				solution = total
				consecutive = consec
	return str(solution)


if __name__ == "__main__":
	print(compute())