max_number = 2000000
#max_number = 10
priem = []
for number in range(1, max_number):
    x=0
    for i in  range(2, number):
        if (number % i) == 0:
            break # geen priemgetal
        else:
            x += 1
    if(x == number-2):
        priem.append(number)
print(priem)
print("Total " + str(len(priem)) + " primenumbers found.")
print("Sum of primes under: " + str(max_number) + ": " + str(sum(priem)))
