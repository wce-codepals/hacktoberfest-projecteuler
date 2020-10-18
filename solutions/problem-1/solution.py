
"""

Problem 1:

We have to find the sum of all the multiples of 3 or 5 below 1000.



"""

# Simple version with list comprehension

def find_sum_of_multiples(n):

    multiples = [num for num in range(n) if num % 3 == 0 or num % 5 == 0]

    return sum(multiples)

print(find_sum_of_multiples(1000))

# Faster version with generators

def find_sum_of_multiples(n):

    sum_of_multiples = sum( num for num in range(n) if num % 3 == 0 or num % 5 == 0 )

    return sum_of_multiples

print(find_sum_of_multiples(1000))
