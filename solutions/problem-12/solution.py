from math import *

# Function to calculate the number of divisors of integer n
def divisors(n):
    limit = int(sqrt(n))
    divisors_list = []
    for i in range(1, limit+1, 1):
        if n % i == 0:
            divisors_list.append(i)
            if i != n/i:
                divisors_list.append(n/i)
    return len(divisors_list)
                
# Function to check for triangle number
def isTriangleNumber(n):
    a = int(sqrt(2*n))
    return 0.5*a*(a+1) == n

# Function to calculate the last term of the series adding up to the triangle number    
def lastTerm(n):
    if isTriangleNumber(n):
        return int(sqrt(2*n))
    else:
        return None


# First number 'check' to have 500 divisors
check = 2**4 * 3**4 * 5**4 * 7 * 11

# Starting from 'check', iterate sequentially checking for the next 'triangle' number
while not isTriangleNumber(check):
    check += 1

# Calculate the last term of the series ('seriesLastTerm') that adds up to the newly calculated triangle number 'check'
seriesLastTerm = lastTerm(check)

# Iterate over triangle numbers checking for divisors > 500
while divisors(check) <= 500:
    # add the next term to check to get the next triangle number
    check += (seriesLastTerm + 1)
    seriesLastTerm += 1

print(check)