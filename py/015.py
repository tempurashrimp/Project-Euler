

''' Problem 015:
    Starting in the top left corner of a 2 * 2 grid, and only being able to move to the 
    right and down, there are exactly 6 routes to the bottom right corner. How many such 
    routes are there through a 20 * 20 grid? '''

def solution(n) -> int:
    n = int(n)
    # The function takes one input n, which
    # represents the size of the n * n grid.
    sum = 1

    # Calculate the value of n choose
    # r using the binomial coefficient formula
    for i in range(1, n + 1):
        # (n + i) is actually (2n - n + i)
        sum = sum * (n + i) // i

    return sum


def main():
    n = input("Type an integer: ")
    print(f"Number of paths in an {n} * {n} grid is {solution(n)}")
    
if __name__ == "__main__":
    main()
    
# Solved 26th July 2025.