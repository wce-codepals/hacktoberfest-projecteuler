a = 1
b = a+1
c = b+1
found = False
while (found == False):    
    while (c > b):
        if ((a*a) + (b*b) == (c*c)):
            print("A = %d, B = %d, C = %d" %(a,b,c))
            if (a+b+c) == 1000:
                print("PRODUCT OF PYTHAGOREAN TRIPLET IS: %d" %(a*b*c))
                found = True
                break
        b = b+1
        c = 1000-a-b
    a = a+1
    b = 2
