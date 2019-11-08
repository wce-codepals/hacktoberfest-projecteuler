import datetime
import math

def nextCheck (n, numList):
	#to optimize elimination of numbers from an integer list (erastotenes crease) one can start the check in n^2
  #As the numbers' elimination changes the values for indexes in the list, we need this function to track the starting point for elimination loop
  # currently going for the minimum in the sublist where x>n^2
	for i in range(0,len(numList)):
		if numList[i]>numList[n]**2:
			return i-1
	return -1

nums=list(range(2,2000000))
maxCheck=0 #just making sure the loop starts
tmp=1 #just making sure the loop starts
while maxCheck<len(nums)-1 and tmp>0:
	tmp=nextCheck(maxCheck, nums)
	prt1=nums[0:tmp]
	prt2=[x for x in nums[tmp:] if x%nums[maxCheck]!=0]
	prt1.extend(prt2)
	nums=prt1
	maxCheck+=1

print(sum(nums))

