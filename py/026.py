
''' Problem 026:
    A unit fraction contains 1 in the numerator. The decimal representation of the unit 
    fractions with denominators 2 to 10 are given: 
    1/2 = 0.5       1/3 = 0.(3)
    1/4 = 0.25      1/5 = 0.2
    1/6 = 0.1(6)    1/7 = 0.(142857) 
    1/8 = 0.125     1/9 = 0.(1)         1/10 = 0.1 
    Where 0.1(6) means 0.16666... , and has a 1-digit recurring cycle. It can be seen that
    1/7 has a 6-digit recurring cycle. Find the value of d < 1000 for which 1/d contains the 
    longest recurring cycle in its decimal fraction part. '''

from PrimeSieve import PrimeSieve

def repetend_length(p) -> int:
    # When p is a prime, the length of the repetend of 1/p is the 
    # multiplicative order of 10 mod p, i.e. return n when 10 ** n % p == 1.
    r = 10 % p
    n = 1
    
    # Simulating long-division, where once the remainder equals 1 once more,
    # a pattern would have been found.
    while r != 1:
        r = (10 * r) % p
        n += 1
    
    return n


def solution(n) -> int:
    n = int(n)
    # The function takes one input, n, which represents the variable d
    # in the original question.
    
    # We are only interested in prime numbers, where for prime numbers p
    # the longest repetend has a maximum of p - 1.
    sieve = PrimeSieve()
    d = set()
    
    while sieve.primes[-1] < n:
        sieve.extend()
    
    # Remove 2 and 5, as they have no repeating segments.
    sieve.primes.remove(2)
    sieve.primes.remove(5)
    sieve.primes = list(filter(lambda x: x < n, sieve.primes))
    
    for p in sieve.primes:
        d.add(repetend_length(p))
    
    # Return max(d) + 1, because the largest multiplicative order
    # is in the form (p - 1) where p is prime. 
    return max(d) + 1


def main():
    n = input("Type an integer: ")
    print(f"Fraction with longest repetend with denominator under {n} is 1/{solution(n)}")
    
    
if __name__ == "__main__":
    main()
    
# Solved 26th August 2025.