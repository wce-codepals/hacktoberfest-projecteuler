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
