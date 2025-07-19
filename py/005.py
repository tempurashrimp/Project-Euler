
''' Problem 005 
    2520 is the smallest number that can be divided by each of the numbers 
    from 1 to 10 without any remainder. What is the smallest positive number 
    that is evenly divisible by all of the numbers from 1 to 20? '''
from math import floor, log10

# Function to check for primes
def isPrime(n) -> bool:    
    # The function takes one input n, which is
    # to be verified as a prime number.
    i = 2
    
    while i * i <= n:
        if (n % i == 0):
            # n is composite
            return False
        else:
            i += 1
        
    # n is prime
    return True


def solution(n):
    n = int(n)
    # The function takes one input n, which is the
    # highest multiple we wish to consider.
    primes = []
    highestMultiple = 1

    # Check every single prime.
    for i in range(2, n + 1):
        if (isPrime(i)):
            primes.append(i) 

    # Compute the powers of each prime.
    for p in primes:
        highestMultiple *= p ** floor((log10(n) / log10(p)))

    return highestMultiple

def main():
    n = input("Type an integer: ")
    print(f"Largest number evenly divisible by 1 through {n} is {solution(n)}")
    
if __name__ == "__main__":
    main()
    
# Solved 19th July 2025.