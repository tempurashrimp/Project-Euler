
/*  Problem 022  
    Using 022.txt, a 46K text file containing over five-thousand first names, begin by sorting 
    it into alphabetical order. Then working out the alphabetical value for each name, multiply
    this value by its alphabetical position in the list to obtain a name score.
    For example, when the list is sorted into alphabetical order, COLIN, which is worth
    3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of
    938 * 53 = 49714. What is the total of all the name scores in the file? */

function solution(names) {
    // names is an array of unsorted names.
    names.sort();

    let totalSum = 0, pos = 1;
    names.forEach(name => function () {
        let sum = 0;

        // Add each letter up.
        name.split("").forEach(letter => function () {
            // charCodeAt of 'A' = 65, hence only subtract 64.
            sum += letter.charCodeAt(0) - 64;
        }());

        totalSum += sum * pos;
        pos++;
    }());

    return totalSum;
}

// Solved 8th August 2025.