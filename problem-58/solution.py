from fractions import Fraction

threshold = Fraction(1, 10)


def ne():
    n = 1
    while True:
        n += 1
        yield (2 * n) ** 2 - 2 * n + 1


def nw():
    n = 1
    while True:
        n += 1
        yield (2 * n) ** 2 + 1


# Southeast corners are never prime


def sw():
    n = 1
    while True:
        n += 1
        yield (2 * n) ** 2 + 2 * n + 1


def is_prime(n):
    if n in [2, 3, 5, 7, 11, 13, 17, 19]:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    for i in range(6, int(n ** 0.5) + 13, 6):
        if n % (i + 1) == 0 or n % (i - 1) == 0:
            return False
    return True


def main():
    gen = zip(ne(), nw(), sw())
    num, denom = 3, 5

    while Fraction(num, denom) > threshold:
        corners = next(gen)
        num += sum([is_prime(n) for n in corners])
        denom += 4

    print("corners =", denom, "side length =", (denom + 1) // 2)


if __name__ == "__main__":
  main()
