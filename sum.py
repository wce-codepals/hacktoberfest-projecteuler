def s(n):
    total_sum = 0
    for i in range(n):
        if (i % 3 == 0 or i % 5 == 0):
            total_sum += i
    return total_sum;
n=1000
total_sum=s(n)
print("Sum Of 3's and 5's divisible numbers upto 1000 are: "+str(total_sum))