import math
import sys

def probability(q):
    scoring = [0.0] * 51
    scoring[0] = 1.0
    for x in range(1, 51):
        next_scoring = [0.0] * 51
        next_scoring[0] = scoring[0] * x/q
        for y in range(1, 51):
            next_scoring[y] = scoring[y-1] * (1 - x/q) + scoring[y] * x/q
        scoring = next_scoring
    return scoring[20]

def main():
    L, U, epsilon = 50.1, 60.0, 10e-15
    for iteration_count in range(100):
        M = (L + U)/2
        p = probability(M)
        if (math.fabs(p - 0.02) < epsilon):
            print('''%.10f''' % M)
            break
        elif p > 0.02:
            L = M
        else:
            U = M

if __name__ == '__main__':
    sys.exit(main())
