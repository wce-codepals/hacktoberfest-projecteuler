# Project Euler 2019
# Vinicius Rodrigues - viniciusrplima (github)
# 1000-digit Fibonacci number : Problem 25

f1 = 1
f2 = 1

index = 2

while(f2 < 10**999):
    f1, f2 = f2, f1+f2
    index += 1

print(index)
