
import math

"""
    Explanation:
    Solution: Sum 4 artihmetic progressions of rate 8 being careful not to repeat 1
    
    Prog 1: 1, 7, 21, 43, 73, ...
             6  14  22  30  ...   (additions of 8 starting at 6)
    Prog 2: 1, 9, 25, 49, 81, ...
    Prog 3: 1, 3, 13, 31, 57, 91, ...
    Prog 4: 1, 5, 17, 37, 65, ...
"""

dim_spiral = 1001
diagonal_dim = math.floor(dim_spiral/2)
r = 8

counter = 1
init1, init2, init3, init4 = 7, 9, 3, 5
final_sum = init1 + init2 + init3 + init4
while counter < diagonal_dim:
    init1 += 6 + r * counter
    init2 += 8 + r * counter
    init3 += 2 + r * counter
    init4 += 4 + r * counter
    final_sum += init1 + init2 + init3 + init4
    print(final_sum)
    counter += 1

# Just add 1 once
final_sum += 1
print("Sum: {}".format(final_sum))
