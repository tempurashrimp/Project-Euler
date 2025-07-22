
#ifndef PRIMESIEVE_H
#define PRIMESIEVE_H

#include <iostream>
#include <vector>

using namespace std;
using num = unsigned long long;

// Implementation of Sieve based on
// https://www.youtube.com/watch?v=xwM8PGBYazM
class PrimeSieve {
    public:
        vector<num> primes;
        num endSegment;
        PrimeSieve();
        void extend();
};

#endif

// Modified (1st time) 23rd July 2025.