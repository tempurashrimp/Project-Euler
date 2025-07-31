
''' Problem 018:
    By starting at the top of the triangle below and moving to adjacent numbers 
    on the row below, the maximum total from top to bottom is 23.
    3
    7 4
    2 4 6
    8 5 9 3
    That is, 3+7+4+9=23. Find the maximum total from top to bottom of the triangle below: '''
    
def solution() -> int:
    triangle = []
    
    # Read the file
    with open("..\\018.txt") as file:
        for line in file:
            triangle.append([int(number) for number in line.split()])
        
    # The size of the list at row n is n.
    for i in range(1, len(triangle)):
        for j in range(i + 1):
            if j == 0:
                # Element at the first column
                triangle[i][j] += triangle[i - 1][j]
            elif j == i:
                # Element at the last column
                triangle[i][j] += triangle[i - 1][j - 1]
            else:
                # Compare and add the maximum
                triangle[i][j] += triangle[i - 1][j] if \
                triangle[i - 1][j] > triangle[i - 1][j - 1] else triangle[i - 1][j - 1]
                
    return max(triangle[-1])


def main():
    print(f"The largest path sum along the triangle is {solution()}")
    
if __name__ == "__main__":
    main()
    
# Solved 31st July 2025.
    