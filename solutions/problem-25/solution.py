#solution to problem 25

def next_fibonacci(a, b):
    return a + b

# We define fibonacci #1 and #2
Fx_minus_2 = 1
Fx_minus_1 = 1
Fx = 0

# and start off at index 2, which will be increased by one before every comparison loop
index = 2

# compare to 10^99, since it is the lowest number (in base 10) to contain 1000 digits
while(Fx<pow(10,999)):
    Fx = next_fibonacci(Fx_minus_2, Fx_minus_1)
    Fx_minus_2 = Fx_minus_1
    Fx_minus_1 = Fx
    index = index + 1

print index
