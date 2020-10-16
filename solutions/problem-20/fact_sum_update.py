'''
Created by Shouvik Dutta
'''
n=int(input())
fact=1
for i in range(1,n+1):
    fact*=i
ans=0
while fact:
    ans+=(fact%10)
    fact//=10
print(ans)
