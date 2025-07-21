
/*  Problem 008:
    The four adjacent digits in the 1000-digit number that have the
    greatest product are 9 * 9 * 8 * 9 = 5832. Find the thirteen adjacent
    digits in the 1000-digit number that have the greatest product.
    What is the value of this product? */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

using num = unsigned long long;
num solution(num n) {
    // The function takes one input n, which represents the
    // number of consecutive digits to calculate.
    vector<short> digits;

    // Read from file
    ifstream digitsFile("../008.txt");
    char digit;
    while (digitsFile.get(digit)) {
        // Apparently this conversion only converts each
        // character to their respective ASCII code.
        digits.push_back(static_cast<short>(digit) - 48);
    }
    digitsFile.close();

    num largestProduct = 0, product = 0;

    // Repeatedly multiply each sequence of digits.
    for (int i = 0; i < digits.size() - n; i++) {
        product = 1;

        for (int j = i; j < i + n; j++) {
            product *= digits.at(j);
            if (product == 0) {
                // 0 is present in the sequence
                break;
            }

            // Set largestProduct = product if it is greater.
            largestProduct = product > largestProduct ? product : largestProduct;
        }
    }

    return largestProduct;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;

    cout << "The largest product of " << n
        << " consecutive digits is " << solution(n) << endl;

    return 0;
}

// Solved 21st July 2025.