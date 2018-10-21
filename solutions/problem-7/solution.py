import math
 
def counter():
    countprime = 0
    prime = 1
    count_token = 2
    def primecheck(num):
        prime = True
        for i in range(int(math.sqrt(num))):
            i = i+2
            if num%i == 0:
                prime = False
                break
        if num == 2:
            return True
        else:            
            return prime
    while countprime < 10001:
         if primecheck(count_token) == True:
             countprime = countprime + 1
             prime = count_token
         count_token = count_token + 1    
    print "The 10001'st Prime number is: ",prime         
counter()
