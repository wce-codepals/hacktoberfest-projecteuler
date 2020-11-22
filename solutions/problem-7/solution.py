def get10001stPrime():
    number=2
    nPrime=0
    notFound=True
    while(notFound):
        numDiv=0
        for i in range(1,number+1):
            if(number%i==0):
                numDiv+=1
        if(numDiv==2):
            nPrime+=1
        if(nPrime==10001):
            notFound=False
            print("The 10001st prime is : "+(str)(number))
        number+=1
                

get10001stPrime()

