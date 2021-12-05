# a, b, sqrt(a*a+b*b)
# a+b+sqrt(a*a+b*b)=1000
for a in range(1,1000):
	for b in range(a+1,1000):
		c = int((a*a+b*b)**0.5)
		if(a+b+c==1000 and c*c==a*a+b*b):
			print(a,b,c)
			print(a*b*c)
