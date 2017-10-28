def fibonacci():
    f1=1
    f2=1
    n=0
    i=2
    while len(str(n))!=1000:
        n=f1+f2
        f1=f2
        f2=n
        i+=1
    return i

# print(fibonacci())