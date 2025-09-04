## Problem 031: Coin Sums
*In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:*
1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
*It is possible to make £2 in the following way:*
$1×£1 + 1×50\text{p} + 2×20\text{p} + 1×5\text{p} + 1×2\text{p} + 3×1\text{p}$
*How many different ways can £2 be made using any number of coins?*

We can simulate the number of ways through a table.

| Ways to arrange: | 0p  | 1p  | 2p  | 3p  | 4p  | 5p  | 6p  | 7p  | 8p  | 9p  | 10p |
| ---------------- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 1p               | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
| 1p, 2p           | 1   | 1   | 2   | 2   | 3   | 3   | 4   | 4   | 5   | 5   | 6   |
| 1p, 2p, 5p       | 1   | 1   | 2   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |
| 1p, 2p, 5p, 10p  | 1   | 1   | 2   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 11  |

For example, consider the case for 10p. There is one way to arrange 10p in 1p coins. As with both 1p and 2p coins, it is known that it can be expressed as any of the following:
$$
\begin{align}
10\text{p}&=8\text{p} + (2\text{p}) \\
&=6\text{p} + 2(2\text{p}) \\
&=4\text{p} + 3(2\text{p}) \\
 &  \vdots
\end{align}
$$
The number of ways to arrange is based on previous counts, which are recorded in the table. If we let $n_{1}(x)$ denote the number of ways to arrange $x \text{p}$ in 1p coins, and similarly  $n_{1,2}(x)$ denote the number of ways to arrange $x \text{p}$ in both 1p and 2p coins,
$$
\begin{align}
n_{1,2}(10)&=n_{1}(10)+n_{1,2}(8) \\
&=1+[n_{1}(8)+n_{1,2}(6)] \\
&=1+1+[n_{1}(6)+n_{1,2}(4)] \\
&\vdots
\end{align}
$$
Note that the calculation appears to be recursive; hence dynamic programming can be used to evaluate successive values without the need for recursion. In particular, if we let $C=\{ 1,2,5,10,20,50,100,200 \}$, then,
$$
f_{n}(x)=\begin{cases}
f_{n-1}(x)+f_{n}(x-C_{n}), & x\geq C_{n} \\
f_{n-1}(x), & x< C_{n}
\end{cases}
$$
where $f_{n}$ denotes the number of ways to arrange $x$ pence with denominations up to the $n$th element in $C$. There is always exactly 1 way to arrange 0p, and exactly 1 way to arrange in terms of 1p coins. 
```js
function solution(n) {
    let denom = [1, 2, 5, 10, 20, 50, 100, 200];

    let ways = new Array(denom.length).fill(Array(n + 1));
    ways[0][0] = 1;

    for (let i = 0; i < denom.length; ++i) {
        ways[i][0] = 1;
    }

    for (let i = 0; i < denom.length; ++i) {
        let coin = denom[i];

        for (let j = 1; j <= n; ++j) {
            let newCoin = (j >= coin ? ways[i][j - coin] : 0);
            let previous = (i >= 1) ? ways[i - 1][j] : 0;

            ways[i][j] = newCoin + previous;
        }
    }

    return ways[denom.length - 1][n];
}
```
**Solved 4th September 2025.**
**Sources:**
https://how.dev/answers/what-is-coins-sums (On the method used.)
