# soulution based on the very good explanation of the 
# problem on http://www.algorithmist.com/index.php/Coin_Change

coins = [1, 2, 5, 10, 20, 50, 100, 200]
target_value = 200

def count(n, m):
    if n < 0 or m < 0:
        return 0
    if n == 0:
       return 1
    return count(n, m - 1) + count(n - coins[m], m)

if __name__ == '__main__':
    print(count(target_value, len(coins)-1))
