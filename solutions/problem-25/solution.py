#!/bin/env python3

a, b, n = 0, 1, 1
while len(str(b)) < 1000:
    a, b = b, a + b
    n += 1
print(n)
