
''' Problem 010:
    The sum of the primes below 10 is 2+3+5+7=17. Find the sum 
    of all the primes below two million. '''

# Segmented Sieve of Eratosthenes implementation
# https://www.youtube.com/watch?v=xwM8PGBYazM
from itertools import repeat

class PrimeSieve: 
    def __init__(self):
        # Start with primes <= 3^2
        self.primes: list[int] = [2, 3, 5, 7]
        self.end_segment: int = 1
        
    # To check all the primes up to 5^2 and so on,
    # you only need to check for the previous primes (i.e., 2, 3 etc.)
    def extend(self) -> None:
        k = self.end_segment
        p, q = self.primes[k], self.primes[k + 1]
        
        # Range from the square of previous prime to current prime.
        segment = range(p * p, q * q)
        segment_min = min(segment)
        segment_len = len(segment)
        is_prime = [True] * segment_len
        
        for i in range(k + 1):
            # Perform Sieve of Eratosthenes algorithm
            pk = self.primes[i]
            start = segment_min + (-segment_min) % pk
            is_prime[start - segment_min::pk] = repeat(False, len(range(start - segment_min, segment_len, pk)))
            
        self.primes.extend([x for x, prime in zip(segment, is_prime) if prime])
        self.end_segment += 1
        

'''
def primes_less_than(n: int) -> list[int]:
    # Trivial case
    if n <= 2:
        return []
    
    # Create a list of booleans to represent
    # whether a certain number is prime.
    is_prime = [True] * n
    
    # 0 and 2 are not primes.
    is_prime[0:2] = False, False
    
    for i in range(2, isqrt(n)):
        if is_prime[i]:
            # Mark out every single multiple
            for j in range(i * i, n, i):
                is_prime[j] = False
                
    return [i for i in range(n) if is_prime[i]]
'''

def main():
    import time
    target = int(input("Enter an integer: "))
    start = time.perf_counter()
    sieve = PrimeSieve()
    while sieve.primes[-1] < target:
        sieve.extend()
        
    print(len([p for p in sieve.primes if p < target]))
    prime_sum = sum([p for p in sieve.primes if p < target])
    elapsed = time.perf_counter() - start
    print(f"done in {elapsed:2f}s.")
    print(f"Sum of primes under {target} is {prime_sum}")


if __name__ == "__main__":
    main()
    
# Solved 22nd July 2025.