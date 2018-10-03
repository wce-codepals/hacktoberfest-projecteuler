# -*- coding: utf-8 -*-
"""
@author: savit
"""
def isPalindrome(n):
    if(n==n[::-1]):
        return True
    return False


count=0

for i in range(10000):
    found=False
    curNum=i
    for n in range(50):
        revNum=str(curNum)[::-1] 
        revNum=int(revNum)
        curNum=curNum+revNum
        if(isPalindrome(str(curNum))):
            found=True
            break;
    if(not found):
        count+=1

print(count)