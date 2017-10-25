def findsqares(limitNum):
    for i in range(limitNum-1,1,-1):
        for j in range(1,i):
            for k in range(j,i):
                total = i + j + k
                if((total == limitNum) and (i**2 == k**2 + j**2 )):
                    print("value 1: "+str(k))
                    print("value 2: "+str(j))
                    print("value 3: "+str(i))
                    print("*******")
                    return i*j*k
                elif(total < limitNum):
                    continue
                else:
                    break

print("product of values are: " + str(findsqares(1000)))
