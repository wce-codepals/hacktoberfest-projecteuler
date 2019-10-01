count = 2
num = 4
while True :
    flag = 1
    n = num//2
    for i in range(2,n+1):
        if num%i == 0 :
            flag = 0
            break
    if flag == 1 :
        count += 1
        if count == 10001 :
            print(num)
            break
    num += 1    
        
