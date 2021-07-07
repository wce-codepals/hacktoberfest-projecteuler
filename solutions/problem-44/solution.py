def is_pentagonal(n):
    """function to check if the number
    is pentagonal number or not"""
    if (1+(24*n+1)**0.5) % 6 == 0:
        return True
    return False

# flag to check if the number is found or not
flag = True
i = 1
while flag:
    for j in xrange(1, i):
        a = i*(3*i-1)/2
        b = j*(3*j-1)/2
        if is_pentagonal(a+b) and is_pentagonal(a-b):
            return(a-b)
            flag = False
            break
    i += 1
