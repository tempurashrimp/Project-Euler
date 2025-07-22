
from itertools import repeat

# Segmented Sieve of Eratosthenes implementation
# https://www.youtube.com/watch?v=xwM8PGBYazM
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
        
# Modified (1st time) 23rd July 2025.
        