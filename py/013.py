
''' Problem 013:
    Work out the first ten digits of the sum of the 
    following one-hundred -digit numbers. '''
    
def solution() -> str:
    sum = 0
    
    # Since Python has built-in large number representation,
    # no need to define a new large number class.
    with open("..\\013.txt") as file:
        for line in file:
            sum += int(line)
            
    return str(sum)[:10]

def main():
    print(f"The first 10 digits of the sum are {solution()}")
    
if __name__ == "__main__":
    main()
    
# Solved 25th July 2025.
    