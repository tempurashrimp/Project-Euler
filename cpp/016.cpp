
/*  Problem 016:
    2^15= = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. 
    What is the sum of the digits of the number 2^1000? */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

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
        int digit = (shorterNumber.at(i) - 48) + (longerNumber.at(i) - 48) + carry;

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

// Define multiplication for the large number class.
LargeNumber operator* (const LargeNumber &n1, const LargeNumber &n2) {
    LargeNumber product(""); 

    int carry = 0;
    string shorterNumber, longerNumber;
    size_t shorterLength, longerLength;

    if (n1.number.length() < n2.number.length()) {
        longerNumber = n2.number;
        longerLength = n2.number.length();
        shorterNumber = n1.number;
        shorterLength = n1.number.length();
    } else {
        longerNumber = n1.number;
        longerLength = n1.number.length();
        shorterNumber = n2.number;
        shorterLength = n2.number.length();
    }

    // Reverse the order of digits.
    reverse(shorterNumber.begin(), shorterNumber.end());
    reverse(longerNumber.begin(), longerNumber.end());

    for(size_t i = 0; i < shorterLength; i++) {
        LargeNumber innerProduct("");
        int currentDigit = shorterNumber.at(i) - '0';
        carry = 0;

        for (size_t j = 0; j < longerLength; j++) {
            int digit = currentDigit * (longerNumber.at(j) - '0') + carry;
            carry = digit / 10;
            digit = digit % 10;

            // Push back the digits.
            innerProduct.number.push_back(digit + '0');
        }

        if (carry) {
            innerProduct.number.push_back(carry + '0');
        }

        // Because of push_back(), the digits are written in reverse.
        reverse(innerProduct.number.begin(), innerProduct.number.end());

        // Place value conversion
        for (size_t j = 0; j < i; j++) {
            innerProduct.number.push_back('0');
        }

        // Add each small product to the final product
        product = product + innerProduct;
    }

    return product;
}

int solution() {
    // 2^1000 = (2^50)^20
    LargeNumber twoToFifty(to_string(
        static_cast<unsigned long long>(pow(2, 50))));
    LargeNumber twoToAThousand(to_string(
        static_cast<unsigned long long>(pow(2, 50))));

    for (int i = 0; i < 19; i++) {
        twoToAThousand = twoToAThousand * twoToFifty;
    }

    int digitSum = 0;
    for (char digit : twoToAThousand.number) {
        digitSum += (digit - '0');
    }

    return digitSum;
}

int main(void) {
    cout << "The sum of digits in 2^1000 is " << solution();

    return 0;
}

// Solved 28th July 2025.