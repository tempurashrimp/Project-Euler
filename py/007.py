''' Problem 007:
    By listing the first six prime numbers: 2, 3, 5, 7, 11
    and 13, we can see that the 6th prime is 13. What is the
    10000th prime number? '''
    
def solution(n) -> int:
    n = int(n)
    # The function takes one input n, which represents the
    # nth prime number.

    # Skip the first three primes.
    prime = 5
    count = 3

    while (count < n):
        prime += 1
        if (isPrime(prime)):
            count += 1
    
    return prime

# Function to check for primes
def isPrime(n):    
    # The function takes one input n, which is
    # to be verified as a prime number.
    # Note that n > 3.

    # For primes 2 and 3
    if (n % 2 == 0 or n % 3 == 0):
        return False

    # For n >= 5:
    i = 5
    while i * i <= n:
        if (n % i == 0 or n % (i + 2) == 0):
            # n is composite
            return False
        
        i += 6

    # n is prime
    return True

def main():
    n = input("Type an integer: ")
    print(f"The {n}th prime is is {solution(n)}")
    
if __name__ == "__main__":
    main()
    
# Solved 20th July 2025.