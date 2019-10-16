a = [1,1]

def find(data):
    if(data <= a.__len__()):
        return a[data-1]
    else:
        while(a.__len__()!=data):
            a.append(a[-2]+a[-1])
        return a[-1]


val = 4000
g = 0
while(g!=1000):
    g = str(find(val)).__len__()
    val += 1
print(val-1)
