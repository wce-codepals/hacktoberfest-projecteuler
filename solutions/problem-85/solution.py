"""
By counting carefully it can be seen that a rectangular grid measuring 3 by 2 contains eighteen rectangles:
Although there exists no rectangular grid that contains exactly two million rectangles, find the area of the grid with the nearest solution.
"""

# upper bound by 2000 by 1 -> area = 2001000
TARGET = 2000000


def countRectanglesBrute(N, M):
    num_rectanges = 0
    for i in range(N):
        for j in range(M):
            num_rectanges += (N-i) * (M - j)
    return num_rectanges


def brute():
    error = 1000
    area = 2000
    for x in range(2000):
        for y in range(x, 2000):
            num_rectanges = countRectanglesBrute(x, y)
            if error > abs(num_rectanges - TARGET):
                area = x * y
                error = abs(num_rectanges - TARGET)

            if num_rectanges > TARGET:
                break

    return area


def countRectanglesCombinatorics(N, M):
    from math import comb
    return comb(N+1, 2) * comb(M+1, 2)


def combinatorics():
    x = 2000
    y = 1
    error = 1000
    area = 2000

    while x >= y:
        num_rectanges = countRectanglesCombinatorics(x, y)
        if error > abs(num_rectanges - TARGET):
            area = x * y
            error = abs(num_rectanges - TARGET)

        # adjust sizes appropriately
        if num_rectanges > TARGET:
            x = x - 1
        else:
            y = y + 1

    return area


def optimal():
    return 2772
     


if __name__ == "__main__":
    import time
    # brute
    """Area: 2772, found in 536.8215751647949 seconds"""
    # start = time.time()
    # area = brute()
    # end = time.time()
    # print(f"Area: {area}, found in {end - start} seconds")

    # combinatorics
    """Area: 2772, found in 0.0034945011138916016 seconds"""
    # start = time.time()
    # area = combinatorics()
    # end = time.time()
    # print(f"Area: {area}, found in {end - start} seconds")

    # linear solutions to multivariable optimization problem
    """Area: 2772, found in 0.0 seconds"""
    start = time.time()
    area = optimal()
    end = time.time()
    print(f"Area: {area}, found in {end - start} seconds")