*Note: Code solutions provided are only written in JavaScript.*
## Problem 001: Multiples of 3 or 5
*If we list all the natural numbers below $10$ that are multiples of $3$ or $5$, we get $3, 5, 6$ and $9$. The sum of these multiples is $23$. Find the sum of all the multiples of $3$ or $5$ below $1000$.*

First note that
$$
3+6+9+\dots=3(1+2+3+\dots)
$$
and
$$
\sum_{n=1}^{k}n=\frac{1}{2}k(k+1).
$$
The same logic can be applied to the multiples of $5$. The problem can be effectively solved in $\mathcal{O}(1)$ by only computing the whole number part of the quotient. Caution must be taken, as multiples of $15$ will be double-counted.
```js
function solution(n) {
    const highest3 = Math.floor((n - 1) / 3);
    const sum3 = 3 * ((highest3 * (highest3 + 1)) / 2);


    const highest5 = Math.floor((n - 1) / 5);
    const sum5 = 5 * ((highest5 * (highest5 + 1)) / 2);

    const highest15 = Math.floor((number - 1) / 15);
    const sum15 = 15 * ((highest15 * (highest15 + 1)) / 2);

    return sum3 + sum5 - sum15;
}
```
**Solved 17th July 2025.**

## Problem 002: