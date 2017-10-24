# There is a Math solution for this problem.
# The path from first step to final state for a MxN grid has M Down and N Right in routes answer hence
# For a 2x4 grid there is a route such as RDRDRR
# For Count all of these routes we need to calculate permutation with repetition.
# So the answer is (M+N)!/(N! x M!)
# For further information : https://brilliant.org/wiki/permutations-with-repetition/


def factorial(n):
    return n * factorial(n - 1) if n > 1 else 1


grid_size = 40
routes_count = factorial(grid_size)/(factorial(grid_size/2)*factorial(grid_size/2))

print(str(routes_count))
