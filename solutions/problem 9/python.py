for a in range (0,1000):

    for b in range (0,1000):

        for c in range (0,1000):

            if a*a + b*b == c*c and a+b+c == 1000:
                    print (str(a) + " " + str(b) + " " + str(c))
                    break
    
