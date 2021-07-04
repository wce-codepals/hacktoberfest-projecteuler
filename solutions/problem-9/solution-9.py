# -*- coding: utf-8 -*-

for c in range(2, 1000):
    for a in range(1, c):
        b = 1000 - c - a
        if b >= 0:
            if a**2 + b**2 == c**2:
                print(a, b, c)
