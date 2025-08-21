
''' Problem 024: 
    A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation 
    of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, 
    we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
    012   021   102   120   201   210
    What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? '''
    
def solution(n) -> str:
    # The function takes one input n, which represents the
    # nth lexicographic permutation.

    # Upper limit of 10!
    n = int(n)
    n = 3628800 if n > 3628800 else n
    n += 1
    
    # Pre-evaluate factorials
    factorials = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    output = ""
    multiplier = 0
    
    for i in range(9, 0, -1):
        multiplier = n // factorials[i]
        n = n % factorials[i]
            
        output += digits[multiplier]
        del digits[multiplier]
        
        multiplier = 0
        
    # Append the final digit
    output += digits[0]
    return output


def main():
    n = input("Type an integer: ")
    print(f"The {n}th lexicographic permutation is {solution(n)}")
    
    
if __name__ == "__main__":
    main()
    
# Solved 21st August 2025.