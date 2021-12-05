def GetSumOfDivs(n):
    """
    Obtain sum of divisions
    Credit to https://codereview.stackexchange.com/users/118064/wcampos
    """
    i = 2
    upper = n
    total = 1
    while i < upper:
        if n%i == 0:
            upper = n/i
            total += upper
            if upper != i: total += i
        i += 1
    return total


def isabundant(n): return GetSumOfDivs(n) > n
lAbundants = [x for x in range(12, 28123) if isabundant(x) == True]
dAbundants = {x:x for x in lAbundants}

sums = 1
for i in range(2, 28123):
    boo = True
    for k in lAbundants:
        if k < i:
            if (i-k) in dAbundants:
                boo = False
                break
        else : break
    if boo == True: sums += i

print(sums)
