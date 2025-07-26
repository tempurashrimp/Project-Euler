
/*  Problem 015:
    Starting in the top left corner of a 2 * 2 grid, and only being able to move to the 
    right and down, there are exactly 6 routes to the bottom right corner. How many such 
    routes are there through a 20 * 20 grid? */

#include <iostream>

using namespace std;
using num = unsigned long long;

num solution(num n) {
    // The function takes one input n, which
    // represents the size of the n * n grid.
    num sum = 1;

    // Calculate the value of n choose
    // r using the binomial coefficient formula
    for (num i = 1; i <= n; i++){
        // (n + i) is actually (2n - n + i)
        sum = sum * (n + i) / i;
    }

    return sum;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;
    cout << "Number of paths in an " << n << " * " << n << 
        " grid is " << solution(n) << endl;

    return 0;
}

// Solved 26th July 2025.