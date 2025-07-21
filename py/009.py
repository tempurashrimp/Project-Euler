
''' Problem 009:
    A Pythagorean triplet is a set of three natural numbers, a<b<c, for which,
    a^2 + b^2 = c^2  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2. 
    There exists exactly one Pythagorean triplet for which a + b + c = 1000. 
    Find the product abc. '''

def solution(k) -> int:
    k = int(k)
    # The function takes one input k, which represents the
    # number we wish to find the Pythagorean triplet for.
    sum_of_abc, product_of_abc = 0, 0
    m, n = 2, 1
    limit = 1000000

    while sum_of_abc != k and m <= limit:
        # By Euclid's formula, recursively generate
        # Pythagorean triples (without a need to verify.)
        a, b, c = (m * m) - (n * n), 2 * m * n, (m * m) + (n * n)

        sum_of_abc = a + b + c
        product_of_abc = a * b * c

        # m > n > 0.
        if m <= n:
            m += 1
            n = 1
        else:
            n += 1
    
    if m > limit:
        raise RuntimeError("Cannot find Pythagorean triple.")
        return
        
    return product_of_abc

def main():
    n = input("Type an integer: ")
    print(f"The product of the Pythagorean triplet with the sum of {n} is {solution(n)}")
    
if __name__ == "__main__":
    main()
    
# Solved 21st July 2025.