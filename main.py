sum = 0
for i in range(2,20000001):
  b = 0
  
  for j in range(2,i):
    if(i % j == 0):
      b = b + 1
  if(b==0):
    sum  = sum  + i
print(sum)
