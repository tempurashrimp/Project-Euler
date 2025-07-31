
/*  Problem 011:
    In the 20 * 20 grid below, four numbers along a diagonal 
    line have been marked in red. The product of these numbers is 
    26 * 63 * 78 * 13 = 1788696. What is the greatest product of four
    adjacent numbers in the same direction (up, down, left, right, or diagonally) 
    in the 20 * 20 grid? */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
using num = unsigned long long;

num solution() {
    vector<vector<int>> grid;
    num greatestProduct = 0;

    // Read from file
    fstream file;
    string line;

    file.open("../011.txt");

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<int> row;
            // stringstream is like an iterator that yields
            // different words (spaced by spaces).
            stringstream numbers(line);
            string number;

            // Push number by number.
            while (numbers >> number) {
                row.push_back(stoi(number));
            }

            grid.push_back(row);
        }
    } else {
        cerr << "Error in file opening." << endl;
        return 0;
    }

    file.close();
    size_t dimension = grid.size();

    // Read horizontally.
    for (vector<int> row : grid) {
        for (size_t i = 0; i < dimension - 3; ++i) {
            num product = row[i] * row[i + 1] * row[i + 2] * row[i + 3];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    // Read vertically.
    for (size_t i = 0; i < dimension - 3; ++i) {
        for (size_t j = 0; j < dimension; ++j) {
            num product = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    // Read diagonally (\)
    for (size_t i = 0; i < dimension - 3; ++i) {
        for (size_t j = 0; j < dimension - 3; ++j) {
            num product = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    // Read diagonally (/)
    for (size_t i = 0; i < dimension - 3; ++i) {
        for (size_t j = dimension - 1; j > 3; --j) {
            num product = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
            if (product > greatestProduct) {
                greatestProduct = product;
            }
        }
    }

    return greatestProduct;
}

int main() {
    cout << "The largest product of four adjacent digits is "
        << solution() << endl;

    return 0;
}

// Solved 24th July 2025.