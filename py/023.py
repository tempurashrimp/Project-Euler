
''' Problem 023:
    A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
    For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect 
    number. A number n is called deficient if the sum of its proper divisors is less than  n and it is called 
    abundant if this sum exceeds n. As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number 
    that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers 
    greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further 
    by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is 
    less than this limit. Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers. '''
    
def divisor_sum(n: int) -> int:
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


def solution(LIMIT) -> int:
    LIMIT = int(LIMIT)
    
    # Implements a sieve of numbers which cannot be written
    # as the sum of two abundant numbers.
    LIMIT = 28124 if LIMIT > 28124 else LIMIT
    
    deficient_sum = 0
    not_abundant_sum = [True] * (LIMIT + 1)
    abundant_numbers = set()
    
    # 12 is the smallest abundant number.
    for i in range(12, LIMIT + 1):
        if not_abundant_sum[i] and (divisor_sum(i) > i):
            abundant_numbers.add(i)
            abundant = 2 * i
            
            while abundant < LIMIT:
                # Multiples of an abundant number are abundant.
                not_abundant_sum[abundant] = False
                abundant_numbers.add(abundant)
                abundant += i
            
    abundant_numbers = list(abundant_numbers)
    abundant_numbers.sort()
    
    # Mark all numbers that are sums of abundant numbers.
    for i in range(len(abundant_numbers)):
        for j in range(i, len(abundant_numbers)):
            if abundant_numbers[i] + abundant_numbers[j] <= LIMIT:
                not_abundant_sum[abundant_numbers[i] + abundant_numbers[j]] = False
            else:
                break

    
    for i in range(1, LIMIT + 1):
        if not_abundant_sum[i]:
            deficient_sum += i
            
    return deficient_sum


def main():
    n = input("Type an integer: ")
    print(f"Sum of numbers under {n} that cannot be written as abundant numbers is {solution(n)}")
    
    
if __name__ == "__main__":
    main()
    
# Solved 20th August 2025.