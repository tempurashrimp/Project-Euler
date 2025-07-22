
/*  Problem 010:
    The sum of the primes below 10 is 2+3+5+7=17. Find the sum 
    of all the primes below two million. */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using num = long long;

// Implementation of Sieve based on
// https://www.youtube.com/watch?v=xwM8PGBYazM
class PrimeSieve {
    public:
        vector<num> primes;
        num endSegment = 1;
        PrimeSieve() {
            primes = {2, 3, 5, 7};
            endSegment = 1;
        }
        void extend();
};

// To check all the primes up to 5^2 and so on,
// you only need to check for the previous primes (i.e., 2, 3 etc.)
void PrimeSieve::extend() {
    num k = endSegment;
    num p = primes.at(k), q = primes.at(k + 1);
    
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
        // TODO: Fix this part (for some reason the C++ version cannot calculate
        // the value of start correctly.)
        pk = primes.at(i);
        start = segmentMin + (segmentMin % pk);

        // Range from the square of previous prime to current prime.
        // is_prime[start - segment_min::pk] = 
        // repeat(False, len(range(start - segment_min, segment_len, pk)))
        for (size_t j = start - segmentMin; 
            j < segmentLen; j += pk) {
            isPrime.at(j) = false;
        }
    }

    // self.primes.extend([x for x,
    // prime in zip(segment, is_prime) if prime])
    for (size_t j = 0; j < segmentLen; ++j){
        if (isPrime.at(j)) {
            primes.push_back(segmentMin + j);
        }      
    }

    endSegment += 1;

    // Save memory?
    segment.clear();
    isPrime.clear(); 
}

num solution(num n) {
    // The function takes one input n, which represents the
    // limit where we sum prime numbers under.
    num primeSum = 0;
    PrimeSieve sieve;

    while (sieve.primes.back() < n) {
        sieve.extend();
    } 

    for (num prime: sieve.primes) {
        if (prime < n) {
            primeSum += prime;
        } else {
            break;
        }
    }

    return primeSum;
}

int main(void) {
    num n;
    cout << "Input an integer: ";
    cin >> n;

    cout << "The sum of prime numbers under " << n 
    << " is " << solution(n) << endl;

    return 0;
}