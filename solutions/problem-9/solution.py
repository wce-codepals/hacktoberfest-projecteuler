# a**2 + b**2 = c**2
# a+b+c=1000

sum = 1000

exitLoops = False

a = 0
while not exitLoops:
  a = a+1
  b = 0
  while not exitLoops:
    b = b+1
    c = sum-a-b
    if c <= 0:
      break
    elif ((a**2 + b**2) == c**2):
      #print("a={:d}, b={:d}, c={:d}".format(a,b,c))
      print("abc={:d}".format(a*b*c))
      exitLoops = True
    if b>sum:
      break
  if a>sum:
    break
