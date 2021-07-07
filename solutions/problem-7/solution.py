def nth_prime_number(n):
    list_of_prime_number = [2]
    num = 3
    while len(list_of_prime_number) < n:
        for p in list_of_prime_number:
            if num % p == 0:
                break
        else:
            list_of_prime_number.append(num)
        num += 2

    return list_of_prime_number[-1]

# Ask the user about the nth value!

nth = input("Enter The Nth Value : ")
print(nth_prime_number(nth))