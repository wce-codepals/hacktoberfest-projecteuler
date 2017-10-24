#Add Python solution to problem-5
"""
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
"""
check_list = [11, 13, 14, 16, 17, 18, 19, 20]

def find_solution(step):
    while True:
        if all(step % n == 0 for n in check_list):
            return step
        step = step + step

if __name__ == '__main__':
    solution = find_solution(20)
    print (solution)
