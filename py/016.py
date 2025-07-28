
''' Problem 016:
    2^15= = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. 
    What is the sum of the digits of the number 2^1000? '''
    
def solution() -> int:
    two_to_a_thousand = str(2 ** 1000)
    digit_sum = 0
    
    for digit in two_to_a_thousand:
        digit_sum += int(digit)
    
    return digit_sum


def main():
    print(f"The sum of digits in 2^1000 is {solution()}")
    
    
if __name__ == "__main__":
    main()
    
# Solved 28th July 2025.