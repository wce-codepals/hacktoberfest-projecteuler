def evenfibo(n):

        if n==0:
                return 0
        elif n==1:
                return 1
        else:
                return evenfibo(n-1)+evenfibo(n-2)

sum=0
while(sum<4000000):
        if(evenfibo(5)%2==0):
                print(sum)
                sum+=evenfibo(5)

        else:
print("not even")
