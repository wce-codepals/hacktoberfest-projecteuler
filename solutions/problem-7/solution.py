
def is_prime(num):
    counter = num - 1
    while counter >= 2:
        if num % counter == 0:
            return False
        counter -= 1
    return True


i = 0
number = 2  # first prime number
range = 10001
while i < range:
    if is_prime(number):
        i += 1
        print("{}: {}".format(i, number))
    number += 1

print("The 10,001st prime number is {}".format(number-1))
