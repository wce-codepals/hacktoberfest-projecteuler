import math

def find_prime_number(n):

    running_num = 3
    prime_nums = [2]

    while len(prime_nums) - 1 < n:

        is_prime = True

        for prime_num in prime_nums:

            if prime_num >= (running_num / math.log(running_num)):
                # The rest of prime numbers will always give out remainders
                break
            
            if running_num % prime_num == 0:
                is_prime = False
                break
        
        if is_prime:
            prime_nums.append(running_num)

        running_num += 1

    return prime_nums[n - 1]

print(find_prime_number(10001))
