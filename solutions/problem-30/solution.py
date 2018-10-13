def sumOfFifths():
    upperBound = (9**5) * 6
    totalSum = 0
    numbers = []

    for number in range(9,upperBound):
        summation = 0
        numberString = list(str(number))
        for digit in numberString:
            summation += int(digit)**5
        if summation==number:
            numbers.append(number)
            totalSum += summation
    return totalSum

print("Total sum: ", sumOfFifths())
