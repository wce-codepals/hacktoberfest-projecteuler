def calc(n): #function which takes the value 2^1000
    c=0
    while n!=0: #while the number is not zero
        q=n%10 #extract digits
        n=n//10 #remove the digit
        c=c+q #keep adding the removed digit to get the sum
    return c

r=pow(2,1000) #calculating 2^1000
w=calc(r)
print(w)
