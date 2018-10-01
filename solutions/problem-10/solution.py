# Varun Singh
# ans = 142913828922

sieve = []
for i in range(2000000):
    sieve.append(False)
ans = 0
for i in range(2, 2000000):
    if not sieve[i]:
        j = i*2
        while j<2000000:
            sieve[j] = True
            j = j+i
        ans += i
print (ans)
