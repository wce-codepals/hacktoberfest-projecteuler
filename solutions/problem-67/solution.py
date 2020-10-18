"""
Problem 67: https://projecteuler.net/problem=67

The idea behind this solution is to start from the bottom and bubble up.

   3     ->   3      ->   3    ->  23
  7 4        7  4       20 19
 2 4 6     10 13 15
8 5 9 3

Moving from the bottom to the top, we'll replace each number with the sum of itself and the
larger number between the two underneath it.

In the above example, we get 10 13 15 because:
    10 = 2 + max(8, 5)
    13 = 4 + max(5, 9)
    15 = 6 + max(9, 3)
"""


def solve(triangle):
    if len(triangle) == 0:
        return 0

    for i in range(len(triangle) - 2, -1, -1):
        for j in range(len(triangle[i])):
            triangle[i][j] = triangle[i][j] + max(triangle[i + 1][j], triangle[i + 1][j + 1])

    return triangle[0][0]


if __name__ == "__main__":
    triangle = []

    with open("triangle.txt", "r") as fd:
        for line in fd:
            triangle.append(list(map(int, line.split(" "))))

    print(solve(triangle))
