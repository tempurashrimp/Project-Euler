
/*  Problem 022  
    Using 022.txt, a 46K text file containing over five-thousand first names, begin by sorting 
    it into alphabetical order. Then working out the alphabetical value for each name, multiply
    this value by its alphabetical position in the list to obtain a name score.
    For example, when the list is sorted into alphabetical order, COLIN, which is worth
    3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of
    938 * 53 = 49714. What is the total of all the name scores in the file? */

#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

unsigned int solution() {
    // Set automatically sorts for you
    set<string> names;

    // Read from file
    fstream file;
    string name;

    file.open("../022.txt");

    if (file.is_open()) {
        // Read by character, ignoring quotation marks,
        // reading a new name when a comma (,) appears.
        char c;

        while (c = file.get()) {
            if (c == EOF) {
                break;
            } else if (c == '"') {
                continue;
            } else if (c == ',') {
                names.insert(name);
                name = "";
            } else {
                name.push_back(c);
            } 
        }

        // Insert the final name
        names.insert(name);
    } else {
        cerr << "Error in file opening." << endl;
        return 0;
    }

    int pos = 1, nameScore;
    unsigned int totalScore = 0;

    for (string name : names) {
        nameScore = 0;

        for (char c : name) {
            nameScore += (c - 'A') + 1;
        }

        totalScore += (nameScore * pos);
        pos++;
    }

    return totalScore;
}

int main(void) {
    cout << "The total score of all names is " << solution();
    return 0;
}

// Solved 8th August 2025.