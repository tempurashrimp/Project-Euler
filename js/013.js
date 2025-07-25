
/*  Problem 013:
    Work out the first ten digits of the sum of the 
    following one-hundred -digit numbers. */

function solution(arr) {
    let sum = BigInt(0);
    arr.forEach(num => function () {
        sum += BigInt(num)
    }());

    console.log(sum);
    return parseInt((sum + " ").substring(0, 10));
}

// Solved 25th July 2025.