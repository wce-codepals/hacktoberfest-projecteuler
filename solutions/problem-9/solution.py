def storeSqareValues(limitNum):
    sqrevalus = []
    val = 1
    i = 1
    while(i < limitNum): #minimum two valuse shuold be 1 and 2(1^2+2^2=5)
        sqrevalus.append(i)
        i += 1
             
        
    return sqrevalus

def findsqares(limitNum):
    sqareValues = storeSqareValues(limitNum)
    lengtharr = len(sqareValues)
    for i in range(lengtharr-1,1,-1):
        for j in range(lengtharr):
            for k in range(lengtharr):
                total = sqareValues[i] + sqareValues[j] + sqareValues[k]
                if((total == limitNum) and (sqareValues[i]**2 == sqareValues[k]**2 + sqareValues[j]**2 )):
                    print("value 1: "+str(sqareValues[k]))
                    print("value 2: "+str(sqareValues[j]))
                    print("value 3: "+str(sqareValues[i]))
                    print("*******")
                    return sqareValues[k]*sqareValues[k]*sqareValues[k]
                
                    #return (sqareValues[i]*sqareValues[j]*sqareValues[k])
                elif(total < limitNum):
                    continue
                else:
                    break

    
        
print("product of values are: " + str(findsqares(1000)))
