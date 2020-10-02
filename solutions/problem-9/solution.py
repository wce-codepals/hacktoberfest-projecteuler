max_number = 2000000
#max_number = 10
priem = []
for number in range(1, max_number):
    x=0
    for i in  range(2, number):
        if (number % i) == 0:
            break # geen priemgetal
        else:
            x += 1
    if(x == number-2):
        priem.append(number)
print(priem)
print("In totaal " + str(len(priem)) + " priemgetallen gevonden.")
print("Som van alle priemgetallen onder de " + str(max_number) + ": " + str(sum(priem)))
ivo@appelflap project-euler.net % cat problem9.py
search=1000
ok=0
a=1
b=2
c=380
maxa=995
maxb=996
maxc=997

res=[]

while ok < 2:
    while c<maxc:
        while b<maxb:
            while a<maxa:
                if (a<b) & (b<c):
                    if (a**2) + (b**2) == (c**2):
                        ok+=1
                        print(str(a) + ":" + str(b) + ":" + str(c) + " --- " + str(a+b+c))
                        if (a+b+c) == search:
                            print("BINGO!")
                            ok+=1
                            res.append(a)
                            res.append(b)
                            res.append(c)
                            res.append(a*b*c)

                ok=0
                a+=1
            b+=1
            a=3
        c+=1
        b=4


print(res)
