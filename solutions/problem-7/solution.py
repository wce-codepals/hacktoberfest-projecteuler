def euler7(n):
    # first prime number
    prime_list = [2]
    # first prime number to be tested
    num = 3
    while len(prime_list) < n:

        for p in prime_list:
            if num % p == 0:
                break
        else:
            prime_list.append(num)

        num += 2

    print(prime_list[-1])

if __name__ == '__main__':
    euler7(10001)