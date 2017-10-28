def collatz(n):
    length = 1
    while n != 1:
        length += 1
        if n % 2 == 0:
            n /= 2
        else:
            n = (n * 3) + 1
    return length

def longestCollatz(n = 1000000):
    #Time-Space tradeoff, doesn't store previously
    #computed values
    max_num = 1
    max_length = 0
    for i in range(n // 2 - 1, n, 2):
        length = collatz(i)
        if length > max_length:
            max_num = i
            max_length = length
    return max_num


def cacheCollatz(n = 1000000):
    #Space-time tradeoff
    #Compensation is used to compensate for '1' not being
    #in the path of terms 'stored_length' (exits while loop)
    #and it is used to compensate for something already being
    #in the cache.

    max_num = 1
    max_length = 0
    cache = {}
    for i in range(n, 1, -1):
        length = 1
        stored_length = []
        value = i
        #find length of i
        compensation = 1
        while value != 1:
            if value in cache:
                existing_len = cache[value]
                length += existing_len
                compensation = existing_len
                break

            length += 1
            stored_length.append(value)
            if value % 2 == 0:
                value /= 2
            else:
                value = (value * 3) + 1
        #update max length
        if length > max_length:
            max_num = i
            max_length = length
        #update the cache
        for i, item in enumerate(reversed(stored_length)):
            cache[item] = i + 1 + compensation
    return max_num
