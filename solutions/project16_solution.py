def main():
    number = 2 ** 1000
    sum_of_digit = 0
    while number:
        sum_of_digit += number % 10   #This will give the last digit in the number and add to the current sum_of_digit
        number //= 10  #This will reduce the number by reducing the last digit
    return sum_of_digit
    
    
main()
