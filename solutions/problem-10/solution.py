"""
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 Find the sum of all the primes below two million.
"""

def isPrime(no):
    """
    Function returns True if number is prime otherwise returns False.
    To get efficient output in very less time, for a really big data(like 2 million),
    here I have used AKS algorithm.
    You can use other efficient primality-proving algorithm to implement this.

    Resources: 
    1) https://en.wikipedia.org/wiki/AKS_primality_test
    2) https://www.quora.com/Is-every-prime-number-other-than-2-and-3-of-the-form-6k%C2%B11-Is-this-a-proven-result-What-are-other-resources-about-it
    """

    if no == 2:
        return True
    if no == 3:
        return True
    if no % 2 == 0:
        return False
    if no % 3 == 0:
        return False

    tempVariable1 = 5
    tempVariable2 = 2

    while tempVariable1 * tempVariable1 <= no:
        if no % tempVariable1 == 0:
            return False

        tempVariable1 += tempVariable2
        tempVariable2 = 6 - tempVariable2

    return True

def main():
	maxNo = 2000000
	totalPrimeSum = 0

	for i in range(0,maxNo+1):
		if(isPrime(i)):
			totalPrimeSum += i

	print("Sum of all prime number below two-million is: ",totalPrimeSum)


if __name__ == '__main__':
	main()
