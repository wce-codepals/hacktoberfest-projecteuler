numb=1
i=1
prev=0
result = 0
while(i):
    result= numb+prev
    prev=numb
    numb=result
    i+=1
    s = str(result)
    if(len(s) == 1000):
        print(i)
        break
