"""
This solution was got from https://codereview.stackexchange.com/a/143898
"""

from fractions import gcd
from itertools import product

def polygon_area(corners):
    """Return the area of the polygon with the given vertices."""
    n = len(corners)
    area = 0.0
    for i in range(n):
        j = (i + 1) % n
        area += corners[i][0] * corners[j][1]
        area -= corners[j][0] * corners[i][1]
    area = abs(area) / 2.0
    return area

_memo = {}
def lattice(p1, p2):
    """Return the number of lattice points on the line from p1 to p2."""
    t = abs(p2[0] - p1[0]), abs(p2[1] - p1[1])
    if t not in _memo:
        g = gcd(t[0], t[1]) + 1
        _memo[t] = g
    return _memo[t]

def boundary(p1, p2, p3, p4):
    """Return the number of lattice points on the boundary of the
    quadrilateral with vertices p1, p2, p3, p4.

    """
    return lattice(p1, p2) + lattice(p2, p3) + lattice(p3, p4) + lattice(p4, p1) - 4

def interior(p1, p2, p3, p4):
    """Return the number of lattice points in the interior of the
    quadrilateral with vertices p1, p2, p3, p4.

    """
    corners = [p1, p2, p3, p4]
    A = polygon_area(corners)
    B = boundary(p1, p2, p3, p4)
    I = A - B/2 + 1
    return I

def problem504(m=100):
    """Return the number of quadrilaterals with vertices lying at lattice
    points on the coordinate axes, no more than m units from the
    origin, whose interior contains a square number of lattice points.

    """
    squares = set(i ** 2 for i in range(2 * m))
    count = 0
    for a, b, c, d in product(range(1, m + 1), repeat=4):
        I = interior((a, 0), (0, b), (-c, 0), (0, -d))
        if I in squares:
            count += 1
    return count
