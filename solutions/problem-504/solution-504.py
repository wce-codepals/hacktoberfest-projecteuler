from fractions import gcd
from itertools import product
import sys

class Problem():
    def __init__(self):
        self.gcd = {}

    def solve(self):
        for n in [4, 100]:
            print(n, '=>', self.get(n))
            
    def get(self, m):
        self.__init_gcd(m)
        result = 0
        square_set = set([i**2 for i in range(1, 2 * m)])
        performance_counter = 0
        for a, b, c, d in product(range(1,m+1),repeat=4):
            interior_points = self.__get_interior_points(a, b, c, d)
            quadrilateral_result = 1 if interior_points in square_set else 0
            result += quadrilateral_result
            performance_counter += 1
            if performance_counter % 1000000 == 0:
                print(performance_counter, a, b, c, d, quadrilateral_result)
        return result

    def __init_gcd(self, m):
        for a in range(1, m + 1):
            self.gcd[(a, a)] = a
            for b in range(a + 1, m + 1):
                g = gcd(a, b)
                self.gcd[(a, b)] = g
                self.gcd[(b, a)] = g
                
    def __get_interior_points(self, a, b, c, d):
        double_area = a * b + b * c + c * d + d * a
        boundary_points = self.gcd[(a, b)] + self.gcd[(b, c)] + self.gcd[(c, d)] + self.gcd[(d, a)]
        return (double_area - boundary_points + 2) // 2
 
def main():
        problem = Problem()
        problem.solve()
        
if __name__ == '__main__':
    sys.exit(main())
