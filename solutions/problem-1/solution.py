"""
Basically, we're getting all multiples from 3 or 5
To get how many multiples exists, a simple division is enough
To get the sum, we use a inbuilt sum function to a list of integers
"""

def sum_multipies(first_multiple,second_multiple,upto):
    summ=[num for num in range(0,upto) if num%first_multiple==0 or num%second_multiple==0]
    return(sum(summ))


print(sum_multipies(3,5,1000))
