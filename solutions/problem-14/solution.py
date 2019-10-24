best_solution = 0
temp = 0
arr = []
arr.append(0)
arr.append(1)
for i in range(2,10):
    t = i+0
    temp = 0
    while t != 1:
        temp +=1
        if t<i:
            temp += arr[t]
            temp -= 1
            t = 1
        elif t%2 == 0:
            t = int(t/2)
        elif t%2 != 0:
            t = 3*t+1
    arr.append(temp)
    if temp > best_solution:
        best_solution = temp+1
        best_number = i
        
print(best_solution)
print(best_number)
