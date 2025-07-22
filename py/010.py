
''' Problem 010:
    The sum of the primes below 10 is 2+3+5+7=17. Find the sum 
    of all the primes below two million. '''

from itertools import repeat
from PrimeSieve import PrimeSieve

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
# Modified (1st time) 23rd July 2025.