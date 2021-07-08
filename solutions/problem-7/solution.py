from num2words import num2words
import re

total = 0 

for i in range(1,1001):
    total += len(''.join(re.findall(r'[\w]+',num2words(i))))

print(total)
