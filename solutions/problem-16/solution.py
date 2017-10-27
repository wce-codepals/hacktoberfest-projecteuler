def digit_sum(number):
    result = 0
    if number == 0:
        return 0
    else:
        result += number % 10
        return result + digit_sum(number // 10)


if __name__ == "__main__":
    print(str(digit_sum(2**1000)))
