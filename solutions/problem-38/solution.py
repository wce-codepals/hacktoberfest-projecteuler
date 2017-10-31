#!/usr/bin/env python3

current = 0

for i in range(2, 10):

    for n in range(1, 10**(9//i)):
        k = "".join([str(n * e) for e in range(1, i+1)])

        if len(k) == 9 and set(k) == set("123456789"):
            current = max(int(k), current)

print(current)
