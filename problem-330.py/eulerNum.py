from decimal import *

#Decimal Accuracy of formula
getcontext().prec = 10

#n iterations of formula
iterations = 1000000

e = Decimal(0); n = Decimal(1)
getcontext().prec+=1

while(n <= iterations):

    print((1+1/n)**n)

    n+=1

else:

    print("------------------------")
    print("e evaluted as: " + str((1 + 1 / n) ** n))

