#Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.
#
#Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.
#
#We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.
#
#Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.
#
#Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.
#
#Find the least number for which the proportion of bouncy numbers is exactly 99%.

def isIncreasing(num):
    strNum = str(num)
    for i in range(1, len(strNum)):
        lastNum = int(strNum[i - 1])
        currentNum = int(strNum[i])
        if lastNum > currentNum:
            return False
    return True

def isDecreasing(num):
    strNum = str(num)
    for i in range(1, len(strNum)):
        lastNum = int(strNum[i - 1])
        currentNum = int(strNum[i])
        if lastNum < currentNum:
            return False
    return True

def bouncy99():
    number = 100
    bouncyCount = 0

    while True:
        if (bouncyCount / number) == 0.99000000:
            break;
        number += 1
        if isIncreasing(number) or isDecreasing(number):
            continue
        else:
            bouncyCount += 1
    return number

print(bouncy99())