#!/usr/bin/env python3

import math

# We're trying to solve for largest x out of the set of minimum solutions of
# x in the equation x^2 - Dy^2 = 1

# This uses the Chakravala method to calculate the smallest answer for each D
# from 1 to 1000, and returns the maximum value

# https://en.wikipedia.org/wiki/Chakravala_method


def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a % b)

def isnotsquare(N):
  return N != int(math.sqrt(N))**2

def chakravala(N):
  # this returns the minimal solution of x^2 = Ny^2 + 1
  # using Chakravala's method

  # first we solve the equation a^2 - Nb^2 = k
  # for any k such that a and b are coprime
  # for now I'm not sure how to do that, so I'll just crash the program if
  # they're not coprime, and assume just setting b to 1 like they do in
  # Wikipedia will work

  # so the first tuple of (a, b, k) will equal (a, 1, a^2 - N) where a is chosen
  # to minimize k (ie. a^2 is the first square above N)
  a = math.floor(math.sqrt(N))
  b = 1
  k = a**2 - N

  if k == 0:
    a = a + 1
    b = 1
    k = a**2 - N

  assert gcd(a, b) == 1

  while k != 1:
  # while k not in [1, -1, 2, -2, 4, -4]:
    # now we compose this solution with the trivial tuple (m, 1, m^2 - N) to get
    # (a*m + N*b, a + b*m, k*(m^2 - N))
    # we scale this down by k to get
    # ((a*m + N*b)/k)^2 - N((a+b*m)/k)^2 = (m^2 - N)/k
    # and choose m such that all of these quantities are integers and (m^2-N) is
    # minimal
    # the first condition is apparently satisfied when the second quantity
    # (a + b*m) is an integer, and the second solution implies that the optimal solution
    # should be in the neighborhood of math.sqrt(N), so I'm gonna roughly bound
    # by sqrt(N) + k
    # this gives us our next set of (a, b, k)
    # we then reiterate until k is 1
    _, m = min([(abs(m**2 - N), m) for m in range(0, N+abs(k)+1) if (a + b*m) % k == 0])

    # print(N, a, b, k, m)
    assert m is not None

    # now we can generate our next tuple
    assert (a*m + N*b) % k == 0
    assert (a + b*m) % k == 0
    assert (m*m - N) % k == 0
    (a, b, k) = (abs(int((a*m + N*b)//k)), abs(int((a + b*m)//k)), int((m*m - N)//k))
  # print("SOLUTION {} {}". format(a, b))
  return (a, b)

_, result = max([(chakravala(N), N) for N in range(2, 1000+1) if isnotsquare(N)])
print(result)
