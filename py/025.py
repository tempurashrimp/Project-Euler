''' Problem 025: 
    The Fibonacci sequence is defined by the recurrence relation:
    F_n = F_(n - 1) + F_(n - 2), where F_1 = 1 and F_2 = 2. Hence the first
    12 terms will be 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
    The 12th term, F_12, is the first term to contain three digits. What is the
    index of the first term in the Fibonacci sequence to contain 1000 digits? '''

def solution(n) -> int:
    n = int(n)
    # The function takes one input n, which is the number of digits
    # in the Fibonacci term.
    
    fib_term_a = 1
    fib_term_b = 1
    index = 2
    
    while len(str(fib_term_b)) < n:
        fib_term_a, fib_term_b = fib_term_b, fib_term_b + fib_term_a
        index += 1
    
    return index


def main():
    n = input("Type an integer: ")
    print(f"Index of first Fibonacci term with {n} is {solution(n)}")
    
    
if __name__ == "__main__":
    main()
    
# Solved 23rd August 2025.