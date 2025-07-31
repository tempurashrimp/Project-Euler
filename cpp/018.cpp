
/*  Problem 018:
    By starting at the top of the triangle below and moving to adjacent numbers 
    on the row below, the maximum total from top to bottom is 23.
    3
    7 4
    2 4 6
    8 5 9 3
    That is, 3+7+4+9=23. Find the maximum total from top to bottom of the triangle below: */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
using num = unsigned long long;

num solution() {
    vector<vector<int>> triangle;

    // Read from file
    fstream file;
    string line;

    file.open("../018.txt");

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

            triangle.push_back(row);
        }
    } else {
        cerr << "Error in file opening." << endl;
        return 0;
    }

    file.close();

    // The size of the vector at row n is n.
    for (size_t i = 1; i < triangle.size(); i++) {
        for (size_t j = 0; j <= i; j++) {
            if (j == 0) {
                // Element at the first column
                triangle.at(i).at(j) += triangle.at(i - 1).at(j);
            } else if (j == i) {
                // Element at the last column
                triangle.at(i).at(j) += triangle.at(i - 1).at(j - 1);
            } else {
                // Compare and add the maximum
                triangle.at(i).at(j) += (triangle.at(i - 1).at(j) > triangle.at(i - 1).at(j - 1)) ?
                triangle.at(i - 1).at(j) : triangle.at(i - 1).at(j - 1);
            }
        } 
    }
    
    return *max_element(triangle.at(triangle.size() - 1).begin(), 
    triangle.at(triangle.size() - 1).end());
}

int main() {
    cout << "The largest path sum along the triangle is "
        << solution() << endl;

    return 0;
}

// Solved 31st July 2025
