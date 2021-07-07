# pythagorian triplet with a+b+b=1000
status=0
for s in range(3,1000,2):
    for t in range (1,s,2):
        a=s*t
        b=int((pow(s,2)-pow(t,2))/2)
        c=int((pow(s,2)+pow(t,2))/2)
        if(a+b+c==1000):
            print(a*b*c)
            status=1
            break
    if status:
        break