def pythag_triple_sum(n = 1000):
    #returns the product of 3 integers whose sum is n
    #and are also a pythagorean triple.
    for a in range(1, n // 3 + 1):
        for b in range(a + 1, n // 2 + 1):
            c = n - b - a
            if (a ** 2 + b ** 2) == c ** 2:
                return a * b * c

if __name__ == '__main__':
    print(pythag_triple_sum())
