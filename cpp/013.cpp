
/*  Problem 013:
    Work out the first ten digits of the sum of the 
    following one-hundred -digit numbers. */

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class LargeNumber {
public:
    LargeNumber(string n) {
        number = n;
    }

    string number;
};

// Define addition for the large number class.
LargeNumber operator+ (const LargeNumber &n1, const LargeNumber &n2) {
    string sumNumber = ""; 

    int carry = 0;
    string shorterNumber, longerNumber;
    size_t longerLength;

    if (n1.number.length() < n2.number.length()) {
        longerNumber = n2.number;
        longerLength = n2.number.length();
        shorterNumber = n1.number;
    } else {
        longerNumber = n1.number;
        longerLength = n1.number.length();
        shorterNumber = n2.number;  
    }

    // Reverse the order of digits.
    reverse(shorterNumber.begin(), shorterNumber.end());
    reverse(longerNumber.begin(), longerNumber.end());

    // Push back any trailing zeroes to ensure
    // lengths of numbers match.
    while(shorterNumber.length() < longerLength) {
        shorterNumber.push_back('0');
    }

    for(size_t i = 0; i < longerLength; i++) {
        // Calculate digit by digit
        int digit = (shorterNumber[i] - 48) + (longerNumber[i] - 48) + carry;

        if (digit > 9) {
            carry = 1;
            digit -= 10;
        } else {
            carry = 0;
        }

        // Push back the digits.
        sumNumber.push_back(digit + '0');
    }

    // Add a trailing "1" if there is a carry-over.
    if (carry) {
        sumNumber.push_back(carry + '0');
    }

    // Because of push_back(), the digits are written in reverse.
    reverse(sumNumber.begin(), sumNumber.end());
    return LargeNumber(sumNumber);
}

string solution() {
    LargeNumber sum("");
    
    // Read from file
    fstream file;
    string line;

    file.open("../013.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            sum = sum + LargeNumber(line);
        }
    }

    return sum.number.substr(0, 10);
}

int main(void) {
    cout << "The first 10 digits of the sum are " << solution();

    return 0;
}

// Solved 25th July 2025.