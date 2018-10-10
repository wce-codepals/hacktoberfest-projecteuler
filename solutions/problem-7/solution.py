n=10001
primeList= [2, 3, 5, 7, 11,13]
startNum=14
while(len(primeList)!=10002):
    for i in range(2,int(startNum**0.5)+1):
        if(not(startNum%i)):
            break
    else:
        primeList.append(startNum)
    startNum+=1
print(primeList[10000])
