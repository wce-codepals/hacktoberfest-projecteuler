"""
This program generates prime numbers using Sieve Of Eratosthenes method
ref: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

Usage:   >julia solution.jl <prime position you want>
example: >julia solution.jl 10001

if command line argument is not provided then this program will return prime at 10001th position
    as stated in the problem statement.

Author's notes:
- Julia follows 1 - based index unlike many other languages like python, java, c
- Julia also is very fast, so trying to find 10001th Prime shouldn't take more than a second
"""

target_prime_position = 10001 # from the problem statement

# look if the a command line argument is provided
if (size(ARGS)[1] > 0)
    # override the target value
    try
        global target_prime_position = parse(Int, ARGS[1]) # remember 1-based index
    catch ArgumentError
        println("Invalid command line param provided")
    end

end

# calculating the upperbound or number of loops we need to perform
upperbound = target_prime_position * log(target_prime_position * log(target_prime_position))
# convert the float value too Int, Julia is typesafe, i.e., very strict in terms of types
upperbound = round(Int, upperbound)

function get_primes_in_range(limit::Int64)
    """
    this method returns list of prime numbers in given range.
    uses Sieve Of Eratosthenes method to identify the prime numbers.
    for ref: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    """

    # get list of trues like [ture, true, true, true....]
    # we assume all are primes at this point
    numbers = trues(limit)
    digit = 2


    while (digit * digit <= limit)
        # if a digit is prime, all it's multiples are not prime
        if (numbers[digit] == true)
            # start marking from digit^2 to limit, go to digit's multiple and mark as non-prime
            for i in digit * digit:digit:limit
                numbers[i] = false
            end
        end
        digit += 1
    end
    # return list of primes, i.e, which are true
    return [p for p in 2:limit if (numbers[p])]
end



### test
primes = get_primes_in_range(upperbound)
println("$target_prime_position prime is: $(primes[target_prime_position])")