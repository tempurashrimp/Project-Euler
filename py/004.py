
''' Problem 004: 
    A palindromic number reads the same both ways. The largest 
    palindrome made from the product of two 2-digit numbers is 
    9009=91*99. Find the largest palindrome made from the product 
    of two 3-digit numbers. '''
    
def solution(n) -> int:
    n = int(n)
    
    # The function takes one input n, which is the
    # maximum number of digits.
    if (n == 1):
        # Trivial case
        return 9

    # Define lower and upper bounds.
    lower_bound = int(10 ** (n - 1))
    upper_bound = int(10 ** n)
    
    max_palindrome = 0
    # Loop through every single digit.
    # Perhaps by starting at the upper bound, we can
    # reduce the number of computations.
    for i in range(lower_bound, upper_bound):
        for j in range(lower_bound, upper_bound):
            product = i * j
            
            # Checking for palindrome with string operations
            # (it's Python anyway)
            if (product > max_palindrome and
                str(product) == str(product)[::-1]):
                max_palindrome = product
    
    return max_palindrome



def main():
    for n in range(1, 6):
        print(f"The largest composite palindrome with {n} digits is {solution(n)}.")
    
if __name__ == "__main__":
    main()
    
# Solved 18th July 2025.