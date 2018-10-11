from math import factorial

def perm(iter, no_of_perm):
    permnum = no_of_perm
    closest1 = []
    numbers = iter
    used = []
    orig_len = len(iter) + len(used)
    for i in range(1, len(iter) + 1):
        target = permnum - sum(closest1)
        fact = factorial(orig_len - i)
        closest = 0
        a = 0
        for n in range(1, len(iter) + 1):
            df = (n * fact)
            if df < target:
                if df > a:
                    closest = n
                    a = n*fact
        try:
            used.append(str(numbers[closest]))
            del numbers[closest]
        except IndexError:
            pass
        closest1.append(closest*fact)
    return ''.join(used)

n = []
perm_no = int(input('Enter the permutation number you want (ie. the 1000000th permutation)')) # (for prob.24 we want 1000000)
start = int(input("Enter the range between which you want the perm to be. Starting number: ")) # for prob 24 we want 0
end = int(input("Ending Number: ")) # for prob24 we want 9
for i in range(start, end + 1):
    n.append(i)
print(f'Your number is: {perm(n, perm_no)}')