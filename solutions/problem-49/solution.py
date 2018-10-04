import itertools

def is_prime(x):
    return all(x % i for i in range(2, x))


numbers = [str(i) for i in range(10)]
numbers += numbers  # duplicate numbers



for subset in itertools.combinations(numbers, 4): # Get 4 numbers
    nums = []
    for i in itertools.permutations(subset):    # find prime permutations
        n0 = int(''.join(i))
        if is_prime(n0):
            nums.append(n0)

    for n1 in nums:
        for n2 in nums:
            n3 = (2*n2-n1)
            if n1 != 1487 and n1 > 999 and n2 > n1 and n3 in nums:
                print(n1, n2, n3)
                print(f'Answer is {n1}{n2}{n3}')
                exit()
