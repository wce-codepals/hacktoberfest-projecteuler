def fifth_power():
    '''
    finds all numbers that can be written as a sum of all its digits to the fifth power
    :return: sum of that numbers
    '''

    sum = 0  # variable that counts the sum of numbers that we've picked
    numbers = []  # list stores all numbers that we've picked

    # with these loops we go through all numbers 0 to 999999 and test if they satisfy the problem
    for a in range(10):
        for b in range(10):
            for c in range(10):
                for d in range(10):
                    for e in range(10):
                        for f in range(10):
                            number = a*100000 + b*10000 + c*1000 + d*100 + e*10 + f*1
                            if a**5 + b**5 + c**5 + d**5 + e**5 + f**5 == number:
                                numbers.append(number)
                                sum += number
    sum -= 1
    return sum, numbers

print('ans:', fifth_power())
