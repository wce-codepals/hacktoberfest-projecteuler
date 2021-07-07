#
# * Project Euler Problem 8 Solution (solution.py)
# * Author: Rishi Sharma
# * #HacktoberFest
#
s = input()
l = len(s)
maxAns = 0
for i in range(0,l-13):
	ans = 1
	s2 = s[i:i+13]
	print(s2)
	for j in range(0, 13):
		ans*= int(s2[j])
	if ans>maxAns:
		maxAns = ans
print(maxAns)
