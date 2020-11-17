def product(sum):
     for a in range(1, sum):
         for b in range(1, sum - a):
             c = sum - a - b
             if a**2 + b**2 == c**2:
                   print (a*b*c)
                   return a*b*c
             else:
                 pass
     print ('triple doesnt exist')

# Example
product(1000)
product(2000)