
''' Problem 008:
    The four adjacent digits in the 1000-digit number that have the 
    greatest product are 9 * 9 * 8 * 9 = 5832. Find the thirteen adjacent 
    digits in the 1000-digit number that have the greatest product. 
    What is the value of this product? '''
    
    
import os
    
def solution(n) -> int:
    n = int(n)
    # The function takes one input n, which represents the
    # number of consecutive digits to calculate.
    digits = []

    # Read from file
    digits_file = open("..\\008.txt", "r")
    
    while True:
        digit = digits_file.read(1)
        if not digit:
            break
        
        digits.append(int(digit))   
    
    digits_file.close()    

    largest_product, product = 0, 0

    # Repeatedly multiply each sequence of digits.
    for i in range(len(digits) - n):
        product = 1

        for j in range(i, i + n):
            product *= digits[j]
            if product == 0:
                # 0 is present in the sequence
                break

            # Set largest_product = product if it is greater.
            largest_product = product if product > largest_product else largest_product

    return largest_product

def main():
    n = input("Type an integer: ")
    print(f"The largest product of {n} consecutive digits is {solution(n)}")
    
if __name__ == "__main__":
    main()
    
# Solved 21st July 2025.