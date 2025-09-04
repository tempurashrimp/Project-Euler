
''' Problem 031:
    In the United Kingdom the currency is made up of pound (£) and pence (p). 
    There are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
    It is possible to make £2 in the following way:
    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
    How many different ways can £2 be made using any number of coins? '''
    
def solution(n) -> int:
    # The function takes in one input n, which represents the
    # total amount of pence.
    n = int(n)
    
    # ways[i][j] represents the number of ways to arrange j
    # pence into coins up to denom[i].
    denom = [1, 2, 5, 10, 20, 50, 100, 200]
    ways = [[0] * (n + 1)] * len(denom)
    ways[0][0] = 1
    
    # There is always exactly one way to arrange 0p.
    for coin in ways:
        coin[0] = 1
        
    # Loop through available coins.
    for i in range(len(denom)):
        coin = denom[i]
        
        # Loop through each sum.
        for j in range(1, n + 1):
            # Add newCoin if j is greater than the coin value.
            # This also sets the ways to arrange anything in 1p
            # to 1.
            new_coin = ways[i][j - coin] if j >= coin else 0
            previous = ways[i - 1][j] if i > 0 else 0
            
            ways[i][j] = new_coin + previous
            
    return ways[len(denom) - 1][n]


def main():
    n = input("Type an integer: ")
    print(f"Ways to arrange {n}p is {solution(n)}")
    
if __name__ == "__main__":
    main()
    
# Solved 4th September 2025.