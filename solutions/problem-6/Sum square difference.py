def sq_diff(num):
    return sum(range(1,num+1))**2-sum([i**2 for i in range(1,num+1)])

print(sq_diff(100))