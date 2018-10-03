import sys

def fib(n1,n2):
	return n1 + n2

f_n2 = 1 #F(n-2)
f_n1 = 1 #F(n-1)

while True:
	fn = fib(f_n2, f_n1)
	print(fn)
	if len(str(fn)) == 4:
		print(fn)
		sys.exit(0)
	else:
		f_n2 = f_n1
		f_n1 = fn
