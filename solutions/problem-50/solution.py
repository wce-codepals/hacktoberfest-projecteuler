import json

primes_file = 'primes.json'
search_max = 1000000
def main():
    primes = load_primes()
    current_repeats = 1
    for i in range(len(primes)):
        sum_ = 0
        for j in range(current_repeats,1000):
            current = sum(primes[i:i+j])
            if current >= search_max or i * j >= search_max:
                break
            if current in primes and j > current_repeats:
                max_found = current
                current_repeats = j
                print(f'found prime: {max_found} with {current_repeats} consecutive  primes')


def load_primes():
    try:
        fp = open(primes_file, 'r')
        primes = json.load(fp)
    except FileNotFoundError:
        fp = open(primes_file, 'w')
        primes = generate_primes(search_max)
        json.dump(primes, fp)
    finally:
        fp.close()
    return primes

def generate_primes(end=1000, start=2):
    if end < max(start,2):
        raise(ValueError('end value should be a positive integer greater than 1'))
    print(f'generating primes from: {start} to {end}')
    primes = []
    candidates = list(range(2, end + 1))

    while candidates:
        new_prime = candidates.pop(0)
        if new_prime >= start:
            primes.append(new_prime)
        candidates = list(filter(lambda x: x % new_prime != 0, candidates))
    return primes

if __name__ == '__main__':
    main()