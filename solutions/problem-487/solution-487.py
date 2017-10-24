import math
import sys

class PrimeTable():
    def __init__(self, bound):
        self.bound = bound
        self.primes = self.__init_primes()
        
    def __init_primes(self):
        primes = []
        visited = [False] * (self.bound + 1)
        visited[0] = visited[1] = True
        for i in range(2, self.bound + 1):
            if not visited[i]:
                primes.append(i)
            for j in range(i + i, self.bound + 1, i):
                visited[j] = True
        print('Prime count:', len(primes))
        return primes

    def is_prime(self, n):
        assert(n <= self.bound**2)
        for prime in self.primes:
            if n % prime == 0:
                return False
        return True

class BernoulliFormula():
    def __init__(self, prime, k):
        self.__prime = prime
        self.__bernoulli_number = {}
        self.__mod_inverse = {}
        self.__init_binomial_coefficient(k + 3)
    
    def get(self, m, n):
        rv = 0
        for k in range(m + 1):
            c_mod = self.__get_binomial_coefficient(m + 1, k)
            b_mod = self.__get_bernoulli_number(k)
            if k % 1000 == 0:
                print("__get_bernoulli_number =>", k, b_mod)
            x_mod = pow(n, m + 1 - k, self.__prime)
            rv += c_mod * b_mod * x_mod
        rv = (rv * self.__get_mod_inverse(m + 1)) % self.__prime
        return rv

    def __init_binomial_coefficient(self, bound):
        print("__init_binomial_coefficient =>", bound)
        self.__binomial_coefficient = [[1 for j in range(i)] for i in range(bound + 1)]
        for i in range(2, bound + 1):
            for j in range(1, i - 1):
                self.__binomial_coefficient[i][j] = (self.__binomial_coefficient[i-1][j] + self.__binomial_coefficient[i-1][j-1]) % self.__prime

    def __get_bernoulli_number(self, n):
        if n > 1 and n % 2 == 1:
            return 0
        if n not in self.__bernoulli_number:
            if n == 1:
                self.__bernoulli_number[1] = self.__get_mod_inverse(2)
            else:
                rv = 0
                for k in range(n):
                    c_mod = self.__get_binomial_coefficient(n, k)
                    b_mod = self.__get_bernoulli_number(k)
                    x_mod = self.__get_mod_inverse(n - k + 1)
                    rv += c_mod * b_mod * x_mod
                self.__bernoulli_number[n] = (1 - rv) % self.__prime
        return self.__bernoulli_number[n]

    def __get_binomial_coefficient(self, m, n):
        return self.__binomial_coefficient[m+1][n]

    def __get_mod_inverse(self, a):
        if a not in self.__mod_inverse:
            g, x, y = self.__extended_gcd(a, self.__prime)
            if g != 1:
                raise Exception('modular inverse does not exist')
            else:
                self.__mod_inverse[a] = x % self.__prime
        return self.__mod_inverse[a]

    def __extended_gcd(self, a, b):
        if a == 0:
            return (b, 0, 1)
        else:
            g, y, x = self.__extended_gcd(b % a, a)
            return (g, x - (b // a) * y, y)

class Problem():
    def solve(self):
        print(self.f(2, 10))
        print(self.S(4, 100))
        primes = self.__get_primes()
        rv = 0
        for prime in primes:
            t = self.T(10000, 10**12, prime)
            rv += t
            print(prime, t)
        print(rv)
    
    def f(self, k, n):
        return sum([i**k for i in range(1, n + 1)])
    
    def S(self, k, n):
        return (n + 1) * self.f(k, n) - self.f(k + 1, n)
    
    def T(self, k, n, prime):
        formula = BernoulliFormula(prime, k)
        return ((n + 1) * formula.get(k, n) - formula.get(k + 1, n)) % prime

    def __get_primes(self):
        rv = []
        prime_table = PrimeTable(45000)
        for n in range(2 * 10**9, 2 * 10**9 + 2000 + 1):
            if prime_table.is_prime(n):
                rv.append(n)
        return rv

def main():
    problem = Problem()
    problem.solve()

if __name__ == '__main__':
    sys.exit(main())

