n=1000
k=13
num=[int(x) for x in raw_input()]
ans=0
for i in xrange(n-k):
    s=1
    for j in xrange(i,i+k):
        s*=num[j]
    if s!=1:
        ans=max(ans,s)
print ans