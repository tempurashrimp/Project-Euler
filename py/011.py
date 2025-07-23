
''' Problem 011:
    In the 20 * 20 grid below, four numbers along a diagonal 
    line have been marked in red. The product of these numbers is 
    26 * 63 * 78 * 13 = 1788696. What is the greatest product of four
    adjacent numbers in the same direction (up, down, left, right, or diagonally) 
    in the 20 * 20 grid? '''

def solution() -> int:
    grid = []
    greatest_product = 0
    
    # Read from file
    with open("..\\011.txt", "r") as file:
        for line in file:
            row = line.split()
            row = list(map(int, row))
            grid.append(row)

        file.close()

    dimension = len(grid)

    # Read horizontally.
    for row in grid:
        for i in range(dimension - 3):
            product = row[i] * row[i + 1] * row[i + 2] * row[i + 3]
            greatest_product = product if product > greatest_product else greatest_product

    # Read vertically.
    for i in range(dimension - 3):
        for j in range(dimension):
            product = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]
            greatest_product = product if product > greatest_product else greatest_product
    

    # Read diagonally (\)
    for i in range(dimension - 3):
        for j in range(dimension - 3):
            product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]
            greatest_product = product if product > greatest_product else greatest_product
    

    # Read diagonally (/)
    for i in range(dimension - 3):
        for j in range(dimension - 1, 3, -1):
            product = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3]
            greatest_product = product if product > greatest_product else greatest_product
    
    
    return greatest_product


def main():
    print(f"The largest product of four adjacent digits is {solution()}")


if __name__ == "__main__":
    main()
    
# Solved 24th July 2025.