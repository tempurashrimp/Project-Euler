
/*  Problem 024: 
    A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation 
    of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, 
    we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
    012   021   102   120   201   210
    What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? */

#include <iostream>
#include <vector>

using namespace std;

string solution(int n) {
    // The function takes one input n, which represents the
    // nth lexicographic permutation.

    // Upper limit of 10!
    n = (n > 3628800) ? 3628800 : n;
    n++;

    // Pre-evaluate factorials
    int factorials[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    vector<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string output = "";
    int multiplier = 0;

    for (int i = 9; i > 0; i--) {
        multiplier = n / factorials[i];
        n = n % factorials[i];
        
        output.push_back(digits[multiplier]);
        digits.erase(digits.begin() + multiplier);

        multiplier = 0;
    }

    // Append the final digit
    output.push_back(*digits.begin());
    return output;
}

int main(void) {
    int n;
    cout << "Input an integer: ";
    cin >> n;

    
    cout << "The " << n << "th lexicographic permutation is " << solution(n);
    return 0;
}

// Solved 21st August 2025.