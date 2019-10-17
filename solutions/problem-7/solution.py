import math

count = 1
nos =2
val = 1

while(val!=10001):  
    count = count +1
    if(count%2 == 1):
        flag = True
        for i in range(2, int(math.sqrt(count))+1): #check for the divisibility
            if(count%i == 0):
                flag = False
        if flag == True:
            val += 1

print(count)
