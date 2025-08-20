## Problem 021: Amicable Numbers
*Let $d(n)$ be defined as the sum of proper divisors of $n$ (numbers less than $n$ which divide evenly into $n$). If $d(a)=b$ and $d(b)=a$, where $a\neq b$, then $a$ and $b$ are an amicable pair and each of $a$ and $b$ are called amicable numbers.*

*For example, the proper divisors of $220$ are $1,2,4,5,10,11,20,22,44,55$ and $110$; therefore $d(220)=284$. The proper divisors of $284$ are $1,2,4,71$ and $142$; so $d(284)=220$. Evaluate the sum of all the amicable numbers under $10000$.*

Prime numbers can never be amicable. If $p$ is a prime number then $d(p)=1$, and also $d(1)=0$. Hence we can exclude the testing of whether prime numbers are amicable.

```js
import { PrimeSieve } from "./PrimeSieve";
  
function d(n) {
    let sum = 0;

    for (let i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;

            if (n / i != i) {
                sum += n / i;
            }
        }
    }

    return sum - n;
}

function solution(n) {
    let sieve = new PrimeSieve();

    let amicable = [];
    let amicableSum = 0;

    while (n > sieve.primes[sieve.primes.length - 1]) {
        sieve.extend();
    }

    let range = [...Array(n - 2).keys()].map(i => i + 1);
    let nonPrimes = range.filter(prime => !sieve.primes.includes(prime));

    nonPrimes.forEach(a => function () {
        let b = d(a);

        if (a != b && d(b) == a) {
            amicable.push(a);

            if (b < n) {
                amicable.push(b);
            }
        }
    }());

    amicable = new Set(amicable);
    amicable.forEach(i => (amicableSum += i));
    return amicableSum;
}
```
**Solved 7th August 2025.**

## Problem 022: Names Scores
*Using `names.txt`, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score. For example, when the list is sorted into alphabetical order, COLIN, which is worth $3 + 15 + 12 + 9 + 14 = 53$, is the $938^{\text{th}}$ name in the list. So, COLIN would obtain a score of $938\times53 = 49714$. What is the total of all the name scores in the file?*

I will rewrite my code to implement quicksort instead of the built in sort, just for fun; using the built-in sort functions is kinda lame right now.
```js
function solution(names) {
    names.sort();

    let totalSum = 0, pos = 1;
    names.forEach(name => function () {
        let sum = 0;

        name.split("").forEach(letter => function () {
            sum += letter.charCodeAt(0) - 64;
        }());

        totalSum += sum * pos;
        pos++;
    }());

    return totalSum;
}
```
**Solved 8th August 2025.**

## Problem 023: Non-Abundant Sums
*A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of $28$ would be $1+2+4+7+14=28$, which means that $28$ is a perfect number.* *A number $n$ is called deficient if the sum of its proper divisors is less than  $n$ and it is called abundant if this sum exceeds $n$.*

*As $12$ is the smallest abundant number, $1+2+3+4+6=16$, the smallest number that can be written as the sum of two abundant numbers is $24$. By mathematical analysis, it can be shown that all integers greater than $28123$ can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.*

*Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.*

Automatically, $1$ to $23$ cannot be expressed as the sum of two abundant numbers. We can use a sieve implementation to separate numbers that can be expressed as the sum of two abundant numbers. Additionally, note that multiples of abundant numbers are also abundant.
```js
function divisorSum(n) {
    let sum = 0;

    for (let i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
  
            if (n / i != i) {
                sum += n / i;
            }
        }
    }

    return sum - n;
}
  

function solution(LIMIT) {
    LIMIT = LIMIT > 28124 ? 28124 : LIMIT;

    let deficient = 0;
    let notAbundantSum = new Array(LIMIT + 1);
    notAbundantSum.fill(true);
    let abundantNumbers = [];

    for (let i = 12; i < LIMIT + 1; i++) {
        if ((divisorSum(i) > i) && notAbundantSum[i]) {
            abundantNumbers.push(i);
            let abundant = 2 * i;

            while (abundant < LIMIT) {
                notAbundantSum[abundant] = false;
                abundantNumbers.push(abundant);
                abundant += i;
            }
        }
    }

    abundantNumbers = [...new Set(abundantNumbers)].sort((a, b) => a - b);
    
    for (let i = 0; i < abundantNumbers.length; i++) {
        for (let j = 0; j < abundantNumbers.length; j++) {
            if (abundantNumbers[i] + abundantNumbers[j] <= LIMIT) {
                notAbundantSum[abundantNumbers[i] + abundantNumbers[j]] = false;
            } else {
                break;
            }
        }
    }

    for (let i = 1; i < LIMIT + 1; i++) {
        if (notAbundantSum[i]) {
            deficient += i;
        }
    }

    return deficient;
}
```
**Solved 20th August 2025.**
**Sources:**
https://en.wikipedia.org/wiki/Abundant_number#Properties (Properties of abundant numbers)