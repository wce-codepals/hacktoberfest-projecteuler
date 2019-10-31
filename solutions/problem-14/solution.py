"""
Longest Collatz sequence

Problem 14
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
"""


def longest_chain(n):
    number, chain_max = 0, 0

    for i in range(1, n + 1):
        num = i
        chain = 0
        while num != 1:
            chain += 1
            if num % 2 == 0:
                num //= 2
            else:
                num = 3 * num + 1

        if chain > chain_max:
            chain_max = chain
            number = i
            print(f"Chain winner: {number} chain lenght: {chain_max}")

    return number, chain_max


if __name__ == "__main__":
    N = 1000000
    number, chain_len = longest_chain(N)
    print(f"Longest chain of lenght {chain_len} produces number: {number}")
