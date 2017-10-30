import math

abc_sum = 1000

# actually a+b+c = 1000 equals to 2000(a+b) = 10^6 + 2ab (a small exercise), 
# so we'll solve the latter problem trying to find a and b needed
solution_found = False
for a in range(1, 1000):
    for b in range(1, 1000):
        if 1000 * (a+b) == 500000 + a*b:
            print("solution:", "a:", a, "b:", b, "c:", math.sqrt(a**2 + b**2))
            solution_found = True
            break
    if solution_found:
        break
            