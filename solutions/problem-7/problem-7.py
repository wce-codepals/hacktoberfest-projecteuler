import sys

def main():
    primes = set(range(2, 200000))
    for i in range(2, 200000): 
        primes -= set(range(2*i, 200000, i))
    print(sorted(primes)[10000])
    
if __name__ == '__main__':
    sys.exit(main())
