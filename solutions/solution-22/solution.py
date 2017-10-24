import csv

with open('names.txt') as f:
    l = csv.reader(f, skipinitialspace=True)
    for name in l:
        print(name)

f_sum = 0
for i, n in enumerate(sorted(name, key=str.lower), start=1):
    print(n)
    s = 0
    for c in n:
        s += ord(c) - 64
    f_sum += i * s
print(f_sum)
