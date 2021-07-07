# number under one million that produces the longest Collatz sequence
sequence = [0 for i in range(1000000)]
sequence[1] = 1

def collatz_squence(num):
    if num<1000000 and sequence[num] > 0: return sequence[num]
    elif num%2 == 0: return (1 + collatz_squence(int(num/2)))
    else : return (1 + collatz_squence(3*num + 1))

for i in range(2,1000000):
    sequence[i] = collatz_squence(i)
print(str(sequence.index(max(sequence))))