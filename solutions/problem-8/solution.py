t = int(input().strip())
for i in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = input().strip()
    max_product = 0
    for j in range(len(num)-k):
        product = 1
        for l in range(k):
            product *= int(num[j+l])
        if product > max_product:
            max_product = product
    print(max_product) 
