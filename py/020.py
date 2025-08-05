
''' Problem 020:
    n! means n * (n - 1) * ... * 3 * 2 * 1.
    For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
    and the sum of the digits in the number 10! is 
    3 + 6 + 2 + 8 + 8 + 0 + 0 = 27. Find the sum of the digits 
    in the number 100! '''
    
def solution(n) -> int:
    n = int(n)
    # The function takes one input n,
    # which we calculate its factorial of.
    
    # ONE-LINER!
    # Explanation: Convert factorial(n) to str, then
    # convert each digit to an int in a list, then
    # add up all digits.
    from math import factorial
    return sum(list(map(int, list(str(factorial(n))))))


def main():
    n = input("Type an integer: ")
    print(f"Sum of digits in {n}! is {solution(n)}.")
    
    
if __name__ == "__main__":
    main()
    
# Solved 5th August 2025.