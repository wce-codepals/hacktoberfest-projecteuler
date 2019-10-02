# Kenneth Nero: 10/1/2019

end = 100        # Set to what ever you want to sum/square
sumofSquares = 0 # Running counter for sum of squares
squareOfSums = 0 # Running counter for square of sums

# Primary work loop. Go to end+1 since Python stops one before
# the top of the range specified
for i in range(1, (end+1)):
    squareOfSums = squareOfSums + i
    sumofSquares = sumofSquares + (i**2)

# Square the final sum once outside the loop
squareOfSums = squareOfSums ** 2

# Format output to terminal
print("Sum of squares from 1 to "+str(end)+": "+str(sumofSquares))
print("Square of sums from 1 to "+str(end)+": "+str(squareOfSums))
print("Difference between the two: "+str(squareOfSums-sumofSquares))
