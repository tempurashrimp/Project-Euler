
/*  Problem 017:
    If the numbers 1 to 5 are written out in words: one, two, three, four, five, 
    then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total. If all the numbers 
    from 1 to 1000 inclusive were written out in words, how many letters would be used? */

function solution(n) {
    // The function takes one input n, which
    // represents the limit of the loop.

    // Lengths is an object representing the letter count of each number
    let lengths = {
        1: 3, 2: 3, 3: 5, 4: 4, 5: 4, 6: 3, 7: 5, 8: 5, 9: 4, 10: 3,
        11: 6, 12: 6, 13: 8, 14: 8, 15: 7, 16: 7, 17: 9, 18: 8, 19: 8, 20: 6,
        30: 6, 40: 5, 50: 5, 60: 5, 70: 7, 80: 6, 90: 6, 0: 0
    };

    let totalLetters = 0;
    for (let i = 1; i <= n; i++) {
        // Special case for "one thousand"
        if (i == 1000) {
            totalLetters += 11;
            break;
        }

        // Hundreds place
        let hundreds = ~~(i / 100);

        // The rest of the numbers
        let underOneHundred = i % 100;

        // Numbers greater than 100
        if (hundreds) {
            totalLetters += 7 + lengths[hundreds];

            // Add "and" where applicable
            if (underOneHundred) {
                totalLetters += 3;
            }
        }

        if (underOneHundred <= 20) {
            // For numbers under twenty
            totalLetters += lengths[underOneHundred];
        } else {
            // For numbers more than 20
            let tens = underOneHundred - (underOneHundred % 10);
            let ones = underOneHundred % 10;

            totalLetters += lengths[tens] + lengths[ones];
        }
    }

    return totalLetters;
}