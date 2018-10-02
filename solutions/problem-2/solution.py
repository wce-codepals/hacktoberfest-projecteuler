# Project Euler Problem 2 Fibonacci Sequence find the sum of evens
# Basic fibonacci sequence 0, 1, 1, 2, 3, 5, 8, 13
# Basic fibonacci sequence is F(n)=F(n-1) + F(n-2)

# Here I have broken it down as c = a + b
def fibonacci_evens(maxnumber):
    # define your starting point
    a = 0
    b = 1
    c = 0
    #creating a holder for the even values to produce the sum needed for the solution
    even_total = 0
    # while the result is less or equal to your maximum defined number
    while(c <= maxnumber):
        # if result is even
        if(c % 2 == 0):
            # add result to previous even numbers total
            even_total = c + even_total
        # the result is equal to the previous 2 values summed together
        c = a + b
        # continue moving the sequence forward
        a = b
        b = c
    # Print the even_total converted to a string to prevent error
    print "The sum of evens in this sequence: " + str(even_total)

def main():
    print "Please input max length of sequence:"
    # Take raw_input from user as an int
    maxnumber = int(raw_input())
    fibonacci_evens(maxnumber)

if __name__ == '__main__':
    main()