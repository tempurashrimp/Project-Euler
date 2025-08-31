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

## Problem 024: Lexicographic Permutations
*A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are: 012   021   102   120   201   210. What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?*

It is known that there are $10!=10(9!)$ possible lexicographic permutations. With a calculator, $100000=2(9!)+6(8!)+6(7!)+2(6!)+5(5!)+4!+2(3!)+2(2!)$.
Step-by-step, the 1000000th lexicographic permutation is
- (2+1)rd element in `[0,1,2,3,4,5,6,7,8,9]=2`
- (6+1)th element in `[0,1,3,4,5,6,7,8,9]=7`
- (6+1)th element in `[0,1,3,4,5,6,8,9]=8`
and so on and so forth.

```js
function solution(n) {
    n = (n > 3628800) ? 3628800 : n;

    let factorials = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];
    let digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
    let output = "";
    let multiplier = 0;

    for (let i = 9; i > 0; i--) {
        while (true) {
            if (n - factorials[i] > 0) {
                multiplier++;
                n -= factorials[i];
            } else {
                break;
            }
        }

        output += (digits[multiplier]);
        digits.splice(multiplier, 1);
  
        multiplier = 0;
    }

    // Append the final digit
    output += digits[0];
    return output;
}
```

**Solved 21st August 2025.**
**Sources:**
https://www.ivl-projecteuler.com/overview-of-problems/5-difficulty/problem-24 (On the method used; the code solutions differ.)

## Problem 025: 1000-digit Fibonacci Number
*The Fibonacci sequence is defined by the recurrence relation:*
*$F_n = F_{n - 1} + F_{n - 2}$, where $F_1 = 1$ and $F_2 = 2$.* 
*Hence the first $12$ terms will be* 
$$
\begin{align}
F_{1}&=1 \\
F_{2}&=1 \\
F_{3}&=2 \\
F_{4}&=3 \\
F_{5}&=5 \\
F_{6}&=8 \\
F_{7}&=13 \\
F_{8}&=21 \\
F_{9}&=34 \\
F_{10}&=55 \\
F_{11}&=89 \\
F_{12}&=144
\end{align}
$$

*The $12$th term, $F_{12}$, is the first term to contain three digits. What is the index of the first term in the Fibonacci sequence to contain $1000$ digits?*

```js
function solution(n) {
    let fibTerms = [1n, 1n, 2n];
    let index = 3;

    while (fibTerms[2].toString().length < n) {
        fibTerms[0] = fibTerms[1];
        fibTerms[1] = fibTerms[2];
        fibTerms[2] = fibTerms[1] + fibTerms[0];

        index++;
    }

    return index;
}
```
**Solved 23rd August 2025.**

## Problem 026: Reciprocal Cycles
*A unit fraction contains $1$ in the numerator. The decimal representation of the unit fractions with denominators $2$ to $10$ are given:*
$$
\begin{align}
1/2&=0.5 \\
1/3&=0.(3) \\
1/4&=0.25 \\
1/5&=0.2 \\
1/6&=0.1(6) \\
1/7&=0.(142857) \\
1/8&=0.125 \\
1/9&=0.(1) \\
1/10&=0.1
\end{align}
$$
*Where $0.1(6)$ means $0.166666\dots$, and has a $1$-digit recurring cycle. It can be seen that $1/7$ has a $6$-digit recurring cycle. Find the value of $d<1000$ for which $1/d$ contians the longest recurring cycle in its decimal fraction part.* 

It turns out that if the denominator is some prime number $p$, then the longest possible repetend length for $\frac{1}{p}$ becomes $(p-1)$. The repetend length is equal to the multiplicative order of $10\text{ mod }p$, which is also computed by finding the smallest natural number $k$ that satisfies $10^{k}\equiv 1\:(\text{mod } p)$.

Therefore, we only need to compute the repetend lengths of prime numbers. Since computing $10^{k}\text{ mod }p$ can be rather tedious for large $k$, we can do this same calculation with the function below.
```js
function repetendLength(p) {
    let r = 10 % p;
    let n = 1;

    while (r != 1) {
        r = (10 * r) % p;
        n += 1;
    }

    return n;
}
```

Consider `repetendLength(7)`. Then each iteration is as follows.

| `n` | `r = (10 * r) % p`     |
| --- | ---------------------- |
| 1   | 3  (note: 10 % 7 = 3.) |
| 2   | 30 % 7 = 2             |
| 3   | 20 % 7 = 6             |
| 4   | 60 % 7 = 4             |
| 5   | 40 % 7 = 5             |
| 6   | 50 % 7 = 1             |
Hence, since $n=6$ we get `repetendLength(7) = 6.` Double-checking this with a computer we in fact get $10^{6}\equiv 1\:(\text{mod }7)$. This is because by the sixth step ($n=6$), we multiplied $10$ to itself $6$ times to simulate $10^{6}$. In fact, this is almost conceptually similar to paper-based long division.

```js
function solution(n) {
    let sieve = new PrimeSieve();
    let d = new Set();

    while (sieve.primes[sieve.primes.length - 1] < n) {
        sieve.extend();
    }
    
    sieve.primes.splice(2, 1);      // 5
    sieve.primes.splice(0, 1);      // 2
    sieve.primes = sieve.primes.filter(p => p < n);

    for (const p of sieve.primes) {
        d.add(repetendLength(p));
    }

    return Math.max(...d);
}
```

**Solved 26th August 2025.**
**Sources:**
https://mathlesstraveled.wordpress.com/2019/02/08/finding-the-repetend-length-of-a-decimal-expansion/ (On the calculation of the repetend length.)
https://en.wikipedia.org/wiki/Repeating_decimal#Fractions_with_prime_denominators (On the properties of repeating decimals.)

## Problem 027: Quadratic Primes
*Euler discovered the remarkable quadratic formula:*
$$
n^{2}+n+41
$$
*It turns out that the formula will produce $40$ primes for the consecutive integer values $0\leq n\leq 39$. However, when $n=40,\:40^{2}+40+41=40(40+1)+41$ is divisible by $41$, and certainly when $n=41,\:41^{2}+41+41$ is clearly divisible by $41$. The incredible formula $n^{2}-79n+1601$ was discoevered, which produces $80$ primes for the consecutive values $0\leq n\leq 79$. The product of the coefficients, $-79$ and $1601$, is $-126479$. Considering quadratics of the form:*
$$
n^{2}+an+b,\:|a|<1000\text{ and }|b|<1000
$$
*Find the product of the coefficients, $a$ and $b$, for the quadratic expression that produces the maximum number of primes for consecutive values of $n$, starting with $n=0$.*

Firstly initialize a hash map of prime numbers for fast checking of primality. Then, notice that since the computation always starts at $n = 0$, $f(0)=b$ and we only need to consider when $b$ is a prime, so we iterate prime values of $b$ under $1000$. Then, we note the following term:
$f(1)=1+a+b.$ For $f(1)$ to be prime, $f(1)=1+a+b\geq 2\implies a\geq 1-b$. Hence the range of $a$ is restricted as $1-b\leq a<1000$.

```js
let sieve = new PrimeSieve();
let primes = new Map();
let primesUnderOneThousand = [];
let lastPrime = 0;

function initialize() {
    while (sieve.primes[sieve.primes.length - 1] < 1000) {
        sieve.extend();
    }

    primesUnderOneThousand = sieve.primes.filter(p => p < 1000);


    while (sieve.primes[sieve.primes.length - 1] < 1000000) {
        sieve.extend();
    }
  
    for (const prime of sieve.primes) {
        primes.set(prime, true);
    }
}


function isPrime(n) {
    if (n < 2) {
        return false;
    }

    while (n > lastPrime) {
        let lastIndex = sieve.primes.length - 1;
        sieve.extend();

        for (let i = lastIndex; i < sieve.primes.length; ++i) {
            primes[sieve.primes[i]] = true;
        }

        lastPrime = sieve.primes[sieve.primes.length - 1];
    }

    if (primes.has(n)) {
        return true;
    }

    return false;
}

function quadratic(a, b) {
    let n = 0;

    while (isPrime((n * n) + (a * n) + b)) {
        n++;
    }

    return n;
}


function solution() {
    initialize();

    let longestA = 0, longestB = 0;
    let longestSequence = 0;

    for (const b of primesUnderOneThousand) {
        for (let a = 1 - b; a < 1000; ++a) {
            let sequence = quadratic(a, b);

            if (sequence > longestSequence) {
                longestSequence = sequence;
                longestA = a, longestB = b;
            }
        }
    }

    return longestA * longestB;
}
```
**Solved 27th August 2025.**

## Problem 028: Number Spiral Diagonals
*Starting with the number $1$ and moving to the right in a clockwise direction a $5$ by $5$ spiral is formed as follows:*
<small style="font-family:monospace;"><b style="color: red">21</b> 22 23 24 <b style="color: red">25</b> <br />20 <b style="color: red">&nbsp;7&nbsp;</b>&nbsp;8 <b style="color: red">&nbsp;9</b> 10 <br />19 &nbsp;6 <b style="color: red">&nbsp;1</b> &nbsp;2 11 <br />18 <b style="color: red">&nbsp;5</b> &nbsp;4 <b style="color: red">&nbsp;3</b> 12 <br /><b style="color: red">17</b> 16 15 14 <b style="color: red">13</b></small>
*It can be verified that the sum of the numbers on the diagonals is $101$. What is the sum of the numbers on the diagonals in a $1001$ by $1001$ spiral formed in the same way?*

First we note that the sum of diagonals is given by:
$$
\begin{align}
1&+3+5+7+9+13+17+21+25 \\
&=1+(3+5+7+9)+(13+17+21+25) \\
\end{align}
$$
Now consider the part $(13+17+21+25)$. Each term can be computed from the dimension by some equation.
$$
\begin{align}
25&=5^{2} \\
21&=5^{2}-4& &=5^{2}-(5-1)\\
17&=5^{2}-8&  &=5^{2}-2(5-1)\\
13&=5^{2}-12& &=5^{2}-3(5-1)
\end{align}
$$
Next, considering the part $(3+5+7+9)$,
$$
\begin{align}
9&=3^{2} \\
7&=3^{2}-2 &&=3^{2}-(3-1)\\
5&=3^{2}-4 &&=3^{2}-2(3-1)\\
3&=3^{2}-6 &&=3^{2}-3(3-1)
\end{align}
$$
Now, we can generalise this by replacing $3$ or $5$ with an odd number $n$.
$$
\begin{align}
\sum &\text{corners} \\
&=n^{2}+[n^{2}-(n-1)]+[n^{2}-2(n-1)]+[n^{2}-3(n-1)] \\
&=n^{2}+(n^{2}-n+1)+(n^{2}-2n+2)+(n^{2}-3n+3) \\
&=4n^{2}-6n+6
\end{align}
$$
To calculate the sum of all diagonals,
$$
\begin{align}
&\sum_{k=3}^{n}(4k^{2}-6k+6)\text{ where }k \text{ is odd} \\
&=\sum_{m=1}^{\frac{1}{2}(n-1)}[4(2m+1)^{2}-6(2m+1)+6] \\
&=\sum_{m=1}^{\frac{1}{2}(n-1)}[4(4m^{2}+4m+1)-(12m+6)+6] \\
&=\sum_{m=1}^{\frac{1}{2}(n-1)}(16m^{2}+4m+4)
\end{align}
$$
Using summation formulae, and let $l=\frac{1}{2}(n-1)$, where $n$ is an odd-numbered dimension:
$$
\begin{align}
&\sum \text{diagonals} \\
&=1+\sum_{m=1}^{l}(16m^{2}+4m+4) \\
&=1+16\sum_{m=1}^{l}m^{2}+4\sum_{m=1}^{l}m+4l \\
&=1+\frac{8}{3}l(l+1)(2l+1)+2l(l+1)+4l \\
&=\frac{16}{3}l^{3}+10l^{2}+\frac{26}{3}l+1
\end{align}
$$

```js
function solution(n) {
    if (!(n % 2)) {
        console.log(" [Dimension must be odd.] ");
        return 0;
    }

  let k = Math.floor((n - 1) / 2);
  let solution = (16 * k * k * k) + (30 * k * k) + (26 * k) + 3;

  return solution / 3;
}
```
**Solved 29th August 2025.**

## Problem 029: Distinct Powers
*Consider all integer combinations of $a^{b}$ for $2\leq a\leq5$ and $2\leq b\leq5$:*
$$
\begin{align}
2^{2}=4, &  & 2^{3}=8, & & 2^{4}=16,& & 2^{5}=32 \\
3^{2}=9,& & 3^{3}=27, & & 3^{4}=81, & & 3^{5}=243 \\
4^{2}=16,& & 4^{3}=64, & & 4^{4}=256, & & 4^{5}=1024 \\
5^{2}=25,& & 5^{3}=125, & & 5^{4}=625, & & 5^{5}=3125
\end{align}
$$
*If they are placed in numerical order, with any repeats removed, we get the following sequence of $15$ distinct terms:*
$$
4,8,9,16,25,27,32,64,81,125,243,256,625,1024,3125
$$
*How many distinct terms are in the sequence generated by $a^{b}$ for $2\leq a\leq 100$ and  $2\leq b\leq 100$?* 

Calculate each term individually, store each term into a set, and measure the length of the set.

```js
function exponentiate(a, b) {
    a = BigInt(a);
    let outcome = BigInt(a);

    for (let i = 1; i < b; i++) {
        outcome *= a;
    }

    return outcome;
}
  

function solution(n) {
    let numbers = new Set();

    for (let a = 2; a <= n; ++a) {
        for (let b = 2; b <= n; ++b) {
            numbers.add(exponentiate(a, b));
        }
    }

    return numbers.size;
}
```
**Solved 31st August 2025.**