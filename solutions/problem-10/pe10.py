# sum of prime nummbers below 2 millions
s=2
a=[2]
c=1
for i in range(3,2000000,2):
    status=1
    for j in a:
        if(i%j==0):
            status=0
            break
    if status:
        s+=i
        a.insert(c,i)
        c+=1
print(s)