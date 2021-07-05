import math


def pythagorean_triplet(num):
    for a in range(1, num):
        for b in range(a, num):
            for c in range(b, num):
                if math.pow(a, 2) + math.pow(b, 2) == math.pow(c, 2) and a < b < c and a+b+c==num:
                    return a, b, c
    return None


a, b, c = pythagorean_triplet(1000)
print("Pythagorean triplets: a={}, b={}, c={}. Product: {}".format(a, b, c, a*b*c))
