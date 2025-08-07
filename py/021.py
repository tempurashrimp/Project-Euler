
''' Problem 021:
    Let d(n) be defined as the sum of proper divisors of n 
    (numbers less than n which divide evenly into n).
    If d(a) = b and d(b) = a, where a =/= b, then a and b are 
    an amicable pair and each of a and b are called amicable numbers.
    For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 
    therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
    Evaluate the sum of all the amicable numbers under 10000. '''
    
from PrimeSieve import PrimeSieve

def d(n: int) -> int:
    # The function takes one input n, which the function
    # computes the factors of.
    factor_sum = 0

    # TODO: use PrimeSieve to factorize
    i = 1
    while i * i <= n:
        if n % i == 0:
            # i is a factor of n
            factor_sum += i

            if (n // i != i):
                factor_sum += n // i
                
        i += 1

    # Since n is repeated
    return factor_sum - n


def solution(n) -> int:
    n = int(n)
    sieve = PrimeSieve()
    amicable = {0}
    amicable_sum = 0
    
    # Prime numbers cannot be amicable.
    # Also 1 is not amicable since d(1) = 1 = d(1).
    while (n > sieve.primes[-1]):
        sieve.extend()
        
    valid_range = {i for i in range(1, n)}
    non_primes = valid_range.difference(set(sieve.primes))
    
    for a in non_primes:
        b = d(a)
        
        if a != b and d(b) == a:
            amicable.add(a)
            
            if b < n:
                # b can be greater than n
                amicable.add(b)
                
    for i in amicable:
        amicable_sum += i
        
    return amicable_sum


def main():
    n = input("Type an integer: ")
    print(f"Sum of digits amicable numbers under {n} is {solution(n)}.")
    
    
if __name__ == "__main__":
    main()
    
# Solved 7th August 2025.