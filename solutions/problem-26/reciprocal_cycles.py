# Project Euler Problem 26 - Reciprocal Cycles - https://projecteuler.net/problem-26
# A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
#
#    1/2 =   0.5
#    1/3 =   0.(3)
#    1/4 =   0.25
#    1/5 =   0.2
#    1/6 =   0.1(6)
#    1/7 =   0.(142857)
#    1/8 =   0.125
#    1/9 =   0.(1)
#    1/10    =   0.1
#    Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
#
# Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
#
# =================================================================================================================================================

# General Solution Notes
# The solution relies on the fact that every fraction's decimal representation can be computed by repetitive long division.
# In long division, if the numberator is less than the denominator (as is the case for a unit fraction), the remainder is multiplied by 10
# until a whole number is yielded. This solution fills a list with remainders until the algorithm re-reaches the first number in the repetend.
# We can also rely on Lagrange's Theorem to dictate that the order of any element of a group divides the order of the group, confirming
# the possible length of the repetend will increase as the denominator increases. Since this means the highest denominator below 1000 will
# also have the longest repetend, we can count down from 1000 and stop at the first repetend we find.

def determine_cycle(denominator):
    cycleLength = 0
    for d in range(denominator, 1, -1):
        if (cycleLength >= d):
            break

        remainders = [0]*d        
        
        rem,dig = 1,0

        while (remainders[rem] == 0 and rem != 0):
            remainders[rem] = dig
            rem = 10 * rem
            rem = rem % d
            dig = dig + 1
           

        if (dig - remainders[rem]) > cycleLength:
            cycleLength = (dig - remainders[rem])
            
    return [dig, cycleLength]

def main():
    longest_cycle = determine_cycle(1000)
    print("The Denominator with the longest reciprocating cycle is ", longest_cycle[0], " with a cycle length of ", longest_cycle[1])

main()
