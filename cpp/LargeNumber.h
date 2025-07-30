
#ifndef LARGENUMBER_H
#define LARGENUMBER_H

#include <string>
#include <algorithm>

using namespace std;
class LargeNumber {
    public:
        string number;
        LargeNumber(string n);
};

LargeNumber operator+ (const LargeNumber &n1, const LargeNumber &n2);
LargeNumber operator* (const LargeNumber &n1, const LargeNumber &n2);

#endif

// Modified (1st time) 30th July 2025.