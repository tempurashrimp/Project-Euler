
''' Problem 027:
    Euler discovered the remarkable quadratic formula n^2 + n + 41.
    It turns out that the formula will produce 40 primes for the consecutive integer values 
    0 <= n <= 39. However, when n = 40,  40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, 
    and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
    The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the 
    consecutive values 0 <= n <= 79. The product of the coefficients -79, and 1601, is
    -126479. Considering quadratics of the form n^2 + an + b, |a| < 1000 and |b| <= 1000,
    Find the product of the coefficients, a and b, for the quadratic expression that produces
    the maximum number of primes for consecutive values of n, starting with n = 0. '''
    
from PrimeSieve import PrimeSieve

sieve = PrimeSieve()
primes = {}
primes_under_one_thousand = []
last_prime = 0

def initialize() -> None:
    global primes_under_one_thousand, last_prime
    
    # Since the maximum value of b is 1000, for the term at n = 0
    # to be prime, we only need to consider prime values for b.
    while sieve.primes[-1] < 1000:
        sieve.extend()
        
    primes_under_one_thousand =  list(filter(lambda x: x < 1000, sieve.primes))

    # Pre-compute primes and store them in a hash-map to speed up ease of checking.
    while sieve.primes[-1] < 1000000:
        sieve.extend()
        
    for prime in sieve.primes:
        primes[prime] = True
        
    last_prime = sieve.primes[-1]
    return


def is_prime(n: int) -> bool:
    global last_prime
    
    # In case the number is greater than the last prime, extend the list of primes.
    if n < 2:
        return False

    while n > last_prime:
        last_index = len(sieve.primes) - 1
        sieve.extend()
        
        for i in range(last_index, len(sieve.primes)):
            primes[sieve.primes[i]] = True
            
        last_prime = sieve.primes[-1]
    
    # Prime is found
    if n in primes:
        return True
    
    return False


def quadratic(a: int, b: int) -> int:
    n = 0
    
    while is_prime((n * n) + (a * n) + b):
        n += 1
        
    return n


def solution() -> None:
    initialize()
    
    longest_a, longest_b = 0, 0
    longest_sequence = 0
    
    for b in primes_under_one_thousand:
        for a in range(1 - b, 1000):
            sequence = quadratic(a, b)
            
            if sequence > longest_sequence:
                longest_sequence = sequence
                longest_a, longest_b = a, b
    
    print("The quadratic equation that satisfies the problem condition is:")
    print(f"n^2 + ({longest_a})n + {longest_b}, and the product of coefficients is {
        longest_a * longest_b}")
    return


if __name__ == "__main__":
    solution()
    
# Solved 27th August 2025.