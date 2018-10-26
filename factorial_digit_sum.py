'''Project Euler problem #20: Factorial and digits sum.
    Example: 10! --> 10 * 9 * 8 * 7..... * 1 = 3628800
        find sum of digits --> 3 + 6 + 2.... = 27
'''

#library
import math #use math library for easier computation of factorial

#functions

def factsum(x):
    num = math.factorial(x) #factorial
    y = sum(map(int, str(num))) #sums all the digits from factorial in num
    print("Factorial is: ", num)
    return y

#IO function   
def main():
    num1 = int(input("Enter a number for n! "))

    print("The sum of digits in the factorial is: ", factsum(num1))

#calling main    
main()

