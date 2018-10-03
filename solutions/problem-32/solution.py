from itertools import permutations 

MIN_MULTIPLICAND_DIGITS = 1
MAX_MULTIPLICAND_DIGITS = 4
MIN_MULTIPLIER_DIGITS = 1
# Since multiplicand and multiplier are interchangeable, we can set one of
# the maximum values to half of the other in order to avoid needless duplication
# of work
MAX_MULTIPLIER_DIGITS = 2
ALL_NUMBERS = ['1', '2', '3', '4', '5', '6', '7', '8', '9']

def find_pandigital_products():
    perms = list(permutations(ALL_NUMBERS))
    results = []

    for p in perms:
        for multic in range(MIN_MULTIPLICAND_DIGITS, MAX_MULTIPLICAND_DIGITS + 1):
            for multip in range(MIN_MULTIPLIER_DIGITS, MAX_MULTIPLIER_DIGITS + 1):
                multiplicand = _tuple_to_int(p[0:multic])
                multiplier = _tuple_to_int(p[multic:multic + multip])
                product = _tuple_to_int(p[multic + multip:])
                if multiplicand * multiplier == product:
                    results.append(product)
    return sum(set(results))

def _tuple_to_int(value):
    return int(''.join([m for m in value]))

print(find_pandigital_products())