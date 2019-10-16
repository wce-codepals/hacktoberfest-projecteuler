from operator import mul

number = "".join([str(i) for i in xrange(10**6+1)])
print reduce(mul, [ int(number[10**i]) for i in xrange(1, 7)]) 
