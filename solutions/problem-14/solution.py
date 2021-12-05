def collatz(n):
    c=1
    while n!=1:
        c=c+1
        if n%2==0:
            n=n/2
        else:
            n=3*n+1
    return c

def main():
    count=0   #current sequence length count
    length=0  
    for n in range(1,1000000):
        count=collatz(n)
        if count > length:
            length=count
            num=n
    print("Longest chain of "+str(length)+" is produced by starting number "+str(num))

if __name__=="__main__":
    main()
