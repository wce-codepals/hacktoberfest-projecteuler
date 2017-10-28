def spt(tripletOf=1000):
    #keep checking if a value of a fits with a value of b to give an
    #integer value of c, for which a+b+c=totalOf (1000)
    # n=0
    a=0
    for b in range(1,tripletOf//2):
        #increase a by 1 everytime b increase, b=a at this point and store a
        a+=1
        prevA=a
        while True:
            #calculate c and check if a+b+c==totalOf, if not, decrease a by 1 till it's
            #0, and when it hits 0, move to the next value of b. When a match is found,
            #return product of a, b and c
            # n+=1
            c=((a**2+b**2)**0.5)
            if a+b+c==tripletOf:
                return a*b*c
            a-=1
            if a==0:
                a=prevA
                break
# print(spt())
