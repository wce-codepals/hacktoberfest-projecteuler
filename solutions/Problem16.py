x = pow(2,1000)
sum = 0
while(x > 0):
    a = x % 10 
    x = x / 10
    sum = sum + a
print (sum)
