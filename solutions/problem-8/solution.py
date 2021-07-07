def highest_adjacent_product(x,adj_num):
    '''
        input:
            x: series of numbers in string
            adj_num: number of adjacent products
        output:
            highest adjacent product of x
    '''
    currentMax = -1
    for i,char in enumerate(x):
        temp = 1
        for j in x[i:i+adj_num]:
            temp = temp*int(j)
        if(temp>currentMax):
            currentMax = temp
    return currentMax




