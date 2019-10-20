def multiplecheck(n):
    sum2=0
    for i in range(0,n):
        if i%3==0 or i%5==0:
            sum2=sum2+i
    return(sum2)

t=int(input())
num=[]
for i in range(t):
    ele=int(input())
    num.append(ele)
for j in num:
    sum1=multiplecheck(j)
    print(sum1)
