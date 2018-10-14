def primeGen(n):
    it = 0
    value = 1
    while it < n:
        value += 1
        if all(map(lambda y: value % y, range(2, int(value ** .5) + 1))):
            it += 1

    return value


if __name__ == '__main__':
    print(primeGen(10001))
