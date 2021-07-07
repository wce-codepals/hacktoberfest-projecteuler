def fib(n):
    '''
        input: Index of Fib
        output: Fib 
    '''
    a = 1
    b = 0
    while n > 1:
        a, b = a+b, a
        n = n - 1
    return a

def first_fib_digits(x):
    '''
        input: number of digit 
        output: first fib index that contain x digits
    '''
    count = 1
    while True:
        if(len(str(fib(count))))>= x:
            return count
        count+=1


