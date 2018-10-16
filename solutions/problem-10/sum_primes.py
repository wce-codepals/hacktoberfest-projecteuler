import math
def prime(n):
  for i in range(2, int(math.sqrt(n)+1)):
    if (n%i==0):
      return False
  return True


sum = 0
for k in range(2, 2000000):
  if (prime(k)):
    sum+=k

print(sum)
