fac = [0 for x in range (200) ]
fac[0] = 1
carry = 0
temp = 0
ind = 1
s = 0
x = 100
for j in range (2,x+1):
    for i in range (200) :
        temp = carry
        carry = (fac[i]*j + carry)//10
        fac[i] = (fac[i]*j + temp)%10
        if (carry !=0 and i>=ind):
            ind = i+1
for k in range (ind,-1,-1) :
    s += fac[k]

print("Sum of digits of 100! is %d" %s)
