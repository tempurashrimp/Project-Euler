
#include <iostream>
#include <numeric>
#include <vector>
#include "PrimeSieve.h"

using namespace std;
using num = unsigned long long;

// Implementation of Sieve based on
// https://www.youtube.com/watch?v=xwM8PGBYazM
PrimeSieve::PrimeSieve() {
    primes = {2, 3, 5, 7};
    endSegment = 1;
}

PrimeSieve::~PrimeSieve() {
    primes.clear();
}

// To check all the primes up to 5^2 and so on,
// you only need to check for the previous primes (i.e., 2, 3 etc.)
void PrimeSieve::extend() {
    num k = endSegment;
    num p = primes[k], q = primes[k + 1];
    
    // Range from the square of the previous prime to current prime
    // segment = range(p * p, q * q)
    num segmentMin = p * p, segmentLen = q * q - p * p;
    vector<num> segment(segmentLen);
    iota(segment.begin(), segment.end(), segmentMin);
    
    // is_prime = [True] * segment_len
    vector<bool> isPrime(segmentLen, true);
    num pk, start;
    
    for (size_t i = 0; i <= k; ++i) {
        // Perform Sieve of Eratosthenes algorithm
        pk = primes.at(i);
        
        // Apparently segment_min + (-segment_min) % pk does not
        // yield the same result in C++. 
        start = segmentMin + (pk - segmentMin % pk) % pk;
        // The second % (% pk) forces the adjustment to be less than
        // pk itself. (If it is not present, then start = segmentMin + pk,
        // is possible which is NOT the smallest multiple of pk >= segmentMin.)

        // Range from the square of previous prime to current prime.
        // is_prime[start - segment_min::pk] = 
        // repeat(False, len(range(start - segment_min, segment_len, pk)))
        for (size_t j = start - segmentMin; 
            j < segmentLen; j += pk) {
            isPrime[j] = false;
        }
    }

    // self.primes.extend([x for x,
    // prime in zip(segment, is_prime) if prime])
    for (size_t j = 0; j < segmentLen; ++j){
        if (isPrime[j]) {
            primes.push_back(segmentMin + j);
        }      
    }

    endSegment += 1;

    // Save memory?
    segment.clear();
    isPrime.clear(); 
}

// Modified (1st time) 23rd July 2025.