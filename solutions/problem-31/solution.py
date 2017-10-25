import sys

"""
Problem 31
"""

# Uses dynamic program/optimal substructure solutions
def findSum(coins, n):
    coinLen = len(coins)
    table = [[0 for x in range(coinLen)] for x in range(n+1)]

    for i in range(coinLen):
        table[0][i] = 1

    for i in range(1, n+1):
        for j in range(coinLen):
            # Count of solutions including coins[j]
            x = table[i - coins[j]][j] if i-coins[j] >= 0 else 0

            # Count of solutions excluding coins[j]
            y = table[i][j-1] if j >= 1 else 0

            # total count
            table[i][j] = x + y

    return table[n][coinLen-1]

targetValue = 200
coinList = "1 2 5 10 20 50 100 200"

coins = map(int,coinList.strip().split(' '))
print findSum(coins, targetValue)
