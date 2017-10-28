#!/usr/bin/env python

#Note: I used the quadratic diophantine equation solver
#for this one.

p=-2
q=-1
k=4
r=-3
s=-2
l=4

x=2
y=0

total=0

while True:
    peri = 3*x-2
    if peri>10**9: break
    eqn = x*x*(3*x*x-8*x+4)
    if x>2 and eqn%16==0 and int(eqn**.5)**2==eqn: total += peri
    t=x
    x = p*x+q*y+k
    y = r*t+s*y+l

p=-2
q=-1
k=-4
r=-3
s=-2
l=-4

x=-2
y=0

while True:
    peri = 3*x+2
    if peri>10**9: break
    eqn = x*x*(3*x*x+8*x+4)
    if x>1 and eqn%16==0 and int(eqn**.5)**2==eqn: total += peri
    t=x
    x = p*x+q*y+k
    y = r*t+s*y+l

print total