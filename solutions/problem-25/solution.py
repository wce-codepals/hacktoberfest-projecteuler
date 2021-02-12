a = [1,1] #inital fibbonachi number 

def find(data):     #finds the fibbonachi number of given index
    if(data <= a.__len__()):
        return a[data-1]        #if number exist then return else its appended sequentially
    else:
        while(a.__len__()!=data):
            a.append(a[-2]+a[-1])
        return a[-1]


val = 4000
g = 0
while(g!=1000):
    g = str(find(val)).__len__()    #finding number of digits
    val += 1
print(val-1)    #final output
