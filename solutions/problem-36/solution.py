maxnum = 1000000    # calculating upto 1 million
Sum = 0

for i in range(maxnum):
    string_base_10 = str(i)  # converting to string in base 10
    string_base_2 = bin(i)[2:]  # converting to string in base 2

    if (string_base_10 == string_base_10[::-1]              # palindrome in base 10
            and string_base_2 == string_base_2[::-1]):     # palindrome in base 2
        Sum += i

print(Sum)
