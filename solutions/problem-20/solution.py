def fatorial(n):
    if(n == 0 or n == 1):
        return 1
    else:
        return fatorial(n-1)*n

def sumFactorial(number):
    numbers = str(fatorial(number))
    total = 0

    for number in numbers:
        total += int(number)
    
    return total

result = sumFactorial(100)

print(result)