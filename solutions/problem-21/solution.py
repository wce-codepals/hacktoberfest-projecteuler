def proper_divisors_sum(x):
    # this part of the code do all the calculation, looking for the divisors and summing them up
    sum = 0
    for number in range(1,x+1):
        if (x%(number) == 0 and number < x):
            sum = sum + number
    return sum

def amicable(x):
    
    # this validates if the number is amicable or not, based on the sums returned
    sum = proper_divisors_sum(x)
    second_sum = proper_divisors_sum(sum)
    third_sum = proper_divisors_sum(second_sum)

    if (x == second_sum and sum == third_sum and x != sum):
        return x
    return 0

sum = 0
for number in range(1,10000):
    sum = sum + amicable(number)
print(sum)

