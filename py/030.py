
''' Problem 030:
    Surprisingly there are only three numbers that can be written as 
    the sum of fourth powers of their digits: 
    1634 = 1^4 + 6^4 + 3^4 + 4^4 
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4 
    As 1 = 1^4 is not a sum it is not included. The sum of these numbers
    is 1634 + 8208 + 9474 = 19316. Find the sum of all the numbers that can
    be written as the sum of fifth powers of their digits. '''
    
def solution() -> int:
    fifth_powers = [0, 1, 32, 243, 1024, 3125, \
                    7776, 16807, 32768, 59049]
    
    # The largest meaningful number is 354294 = 6 * 9^5.
    return sum([i for i in range(2, 354295) 
                if i == sum(fifth_powers[int(d)] for d in str(i))])


def main():
    print(f"Sum of all the numbers that equal the sum of 5th powers of their digits is {solution()}")
    
if __name__ == "__main__":
    main()
    
# Solved 2nd September 2025.