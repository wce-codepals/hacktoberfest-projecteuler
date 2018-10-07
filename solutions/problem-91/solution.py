""" https://projecteuler.net/problem=91

Works in both Python 2 and Python 3

"""
from itertools import product, combinations


def squared_distance_from_points(p1, p2):
    """Return the square of the distance between two points

        Using the square of the distance avoids floating point numbers
        """
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2


def find_right_triangles(max_x, max_y):
    # Accumulator for final answer
    answer = 0

    # Basic numbers to use later
    origin = (0, 0)
    range_x = range(max_x + 1)
    range_y = range(max_y + 1)

    # Enumerate candidates from possible points
    points = product(range_x, range_y)
    pairs = combinations(points, 2)

    for p1, p2 in pairs:
        if p1 == (0, 0):
            # Because combinations are sorted, only point 1 will
            #   be at the origin. Just skip this set.
            continue

        dist1 = squared_distance_from_points(origin, p1)
        dist2 = squared_distance_from_points(origin, p2)
        dist3 = squared_distance_from_points(p1, p2)
        max_dist = max(dist1, dist2, dist3)
        if 2 * max_dist == dist1 + dist2 + dist3:
            # a**2 + b**2 + c**2 = 2*(c**2)
            answer += 1
    return answer


if __name__ == "__main__":
    assert find_right_triangles(2, 2) == 14
    print(find_right_triangles(50, 50))

