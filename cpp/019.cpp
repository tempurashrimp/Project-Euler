
/*  Problem 019:
    How many Sundays fell on the first of the month during the 
    twentieth century (1 Jan 1901 to 31 Dec 2000)? */

#include <iostream>

using namespace std;

int solution() {
    // We save the day of the week as a number from 0 to 6,
    // where 0 represents Sunday, and 6 represents Saturday.
    // 1st January 1901 is a Tuesday.
    int day = 2, firsts = 0;

    for (int year = 1901; year <= 2000; year++) {
        // 2000 is a leap year.
        bool leap = year % 4 ? false : true;

        for (int month = 0; month < 12; month++) {
            switch (month) {
            case 3:  // April
            case 5:  // June
            case 8:  // September
            case 10: // November
                day += 30;
                break;

            case 1:  // February
                day += leap ? 29 : 28;
                break;

            default: // Other months
                day += 31; 
            }

            // Convert to day
            day %= 7;
            firsts += day ? 0 : 1;
        }
    }

    return firsts;
}

int main() {
    cout << "The number of Sundays on the 1st of the month in the 20th century is "
        << solution() << endl;

    return 0;
}

// Solved 4th August 2025