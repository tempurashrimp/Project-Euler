
/*  Problem 010:
    The sum of the primes below 10 is 2+3+5+7=17. Find the sum 
    of all the primes below two million. */

// Implementation of Sieve based on
// https://www.youtube.com/watch?v=xwM8PGBYazM
class PrimeSieve {
    constructor() {
        this.primes = [2, 3, 5, 7];
        this.endSegment = 1;
    }
}


// To check all the primes up to 5^2 and so on,
// you only need to check for the previous primes (i.e., 2, 3 etc.)
PrimeSieve.prototype.extend = function() {
    let k = this.endSegment, p = this.primes[k], q = this.primes[k + 1];
    let segmentMin = p * p, segmentLen = (q * q) - (p * p);
    let segment = [];
    
    // Range from the square of the previous prime to current prime
    // segment = range(p * p, q * q)
    for (let i = 0; i < segmentLen; i++) {
        segment.push(i + segmentMin)
    }

    // is_prime = [True] * segment_len
    let isPrime = new Array(segmentLen).fill(true);
    let pk = 0, start = 0;

    for (let i = 0; i <= k; i++) {
        pk = this.primes[i];
        
        // Apparently segment_min + (-segment_min) % pk does not
        // yield the same result in C++. 
        start = segmentMin + (pk - segmentMin % pk) % pk;
        // The second % (% pk) forces the adjustment to be less than
        // pk itself. (If it is not present, then start = segmentMin + pk,
        // is possible which is NOT the smallest multiple of pk >= segmentMin.)

        // Range from the square of previous prime to current prime.
        // is_prime[start - segment_min::pk] = 
        // repeat(False, len(range(start - segment_min, segment_len, pk)))
        for (let j = start - segmentMin; j < segmentLen; j += pk) {
            isPrime[j] = false;
        }
    }

    
    // self.primes.extend([x for x,
    // prime in zip(segment, is_prime) if prime])
    for (let j = 0; j < segmentLen; ++j){
        if (isPrime[j]) {
            this.primes.push(segmentMin + j);
        }      
    }

    this.endSegment += 1;
}

function solution(n) {
    // The function takes one input n, which represents the
    // limit where we sum prime numbers under.
    let primeSum = 0;
    let sieve = new PrimeSieve();

    while (sieve.primes.back() < n) {
        sieve.extend();
    } 

    sieve.primes.forEach(prime => {
        if (prime < n) {
            primeSum += prime;
        }
    }); 

    return primeSum;
}

// Solved 22nd July 2025.