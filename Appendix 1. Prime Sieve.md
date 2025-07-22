The Sieve of Erathosthenes is originally implemented by creating a boolean list of numbers. Starting from 2, cross out every multiple of 2 in that list. Then, move on to the next unmarked (prime number), 3, and cross out every multiple of 3. Continue until the list has been exhausted.

The Segmented approach effectively implements the same algorithm as the Sieve of Erathosthenes. However, by segmentation of the array of natural numbers, we can save on the RAM used. Henceforth I shall use this prime calculation method.

This particular implementation was originally written in Python; however I have made an attempt to translate it into C++ and JavaScript.

```js
class PrimeSieve {
    constructor() {
        this.primes = [2, 3, 5, 7];
        this.endSegment = 1;
    }
}

PrimeSieve.prototype.extend = function() {
    let k = this.endSegment, p = this.primes[k], q = this.primes[k + 1];
    let segmentMin = p * p, segmentLen = (q * q) - (p * p);
    let segment = [];

    for (let i = 0; i < segmentLen; i++) {
        segment.push(i + segmentMin)
    }

    let isPrime = new Array(segmentLen).fill(true);
    let pk = 0, start = 0;

    for (let i = 0; i <= k; i++) {
        pk = this.primes[i];
        start = segmentMin + (pk - segmentMin % pk) % pk;

        for (let j = start - segmentMin; j < segmentLen; j += pk) {
            isPrime[j] = false;
        }
    }


    for (let j = 0; j < segmentLen; ++j){
        if (isPrime[j]) {
            this.primes.push(segmentMin + j);
        }      
    }

    this.endSegment += 1;
}
```
**Sources:**
https://www.youtube.com/watch?v=xwM8PGBYazM (Implementation of prime sieve)