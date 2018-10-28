def Special():
    for a in range(10):
        for b in range(10):
            for c in range(10):
                if(a+b+c==12 and a**2+b**2-c**2==0 and (c>b>a)):
                    return ( a*b*c )


print(Special())


# replace a+b+c==12 by a+b+c==1000
# replace 10 by 1000