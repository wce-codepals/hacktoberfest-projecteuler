'''
Python solution to Problem 24
Written by sakurakhadag
'''

def factorials(n: int) -> dict:
    '''
    precalculates factorials until n-1
    '''

    factorial = {0:1, 1:1, 2:2}
    for i in range(3,n):
        factorial[i] = factorial[i-1]*i

    return factorial

def main():
    '''
    Find the millionth lexicographic permutation of the digits
    0, 1, 2, 3, 4, 5, 6, 7, 8 and 9
    '''
    n = 10

    factorial = factorials(n)
    digits = [i for i in range(n)] #possible digits

    number = ''
    p = 1000000-1 # find the p'th lexicographic permutation
    for cur_pos in range(0,n):
        sum = 0

        for digit in digits:
            sum+=factorial[n-1-cur_pos] # factorials of number of pos left
            if sum>p: # if we overshoot sum,
                number += str(digit)
                digits.remove(digit)
                p -= sum - factorial[n-1-cur_pos]
                break

    print(f'The millionth lexicographic permuation is {number}')


main()
