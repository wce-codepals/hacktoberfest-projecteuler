# Initial first and seconds number of the Fibonacci sequence
a = 1
b = 1


i = 3

# replace a = a+b and b = a while 
# the sum of both of them exceeds 1000 digits.
while(len(str(a+b))<1000):
    a, b = a+b, a
    i += 1
    
print(str(i))
