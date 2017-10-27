#!/usr/bin/env python3

import sys

target = int(sys.argv[1]) if len(sys.argv) > 1 else 10000


class TrinaryCounter:
    def __init__(self):
        self.val = 1

    def next(self):
        # Get next number
        def return_next_number(v: str):
            if not v:
                return '1'
            elif v[-1] in '01':
                return v[:-1] + str(int(v[-1])+1)
            else:
                return return_next_number(v[:-1]) + "0"
        self.val = int(return_next_number(str(self.val)))
        return self.val


trinary_counter = TrinaryCounter()
trinary_numbers = [1]


def multiples_of_niners_cheat(n):
    size = len(str(n))
    return int(("1" * size) + ("2" * size * 4))


def find_next_multiple(n):
    if set(str(n)) == set("9"):
        # Speeds up by a factor of 1445. Seriously.
        return multiples_of_niners_cheat(n)

    # First, search on the pre-cached entries
    for current in trinary_numbers:
        if current % n == 0:
            return current

    # If it doesn't find, we get the next trinary number and look for a match
    while current % n != 0:
        current = trinary_counter.next()
        trinary_numbers.append(current)
    return current


multiples = []
for i in range(1, target+1):
    n = int(find_next_multiple(i)/i)
    multiples.append(n)
    # print(i, n)

# print(multiples)
print(sum(multiples))
