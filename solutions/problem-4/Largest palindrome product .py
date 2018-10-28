def largest_palindrome_3digit():
    arr_palindrome=[]
    for i in range(1,100):            #replace 100 with 1000 and 1 with 100
        for j in range(1,100):
            value1=list(str((i*j)))
            if(value1==value1[::-1]):
                arr_palindrome.append(int(''.join(value1)))
    arr_palindrome.sort()
    return (arr_palindrome[-1])


print(largest_palindrome_3digit())


