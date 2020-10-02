max_number = 110000
prime = []
for number in range(1, max_number):
    x=0
    for i in  range(2, number):
        if (number % i) == 0:
            break # no prime
        else:
            x += 1
    if(x == number-2):
        prime.append(number)
print("Total of " + str(len(prime)) + " primenumbers found.")
print(prime[10000])
