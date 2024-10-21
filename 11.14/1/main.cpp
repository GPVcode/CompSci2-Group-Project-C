#include <iostream>
#include <vector>
#include <string>

using namespace std;

// vector of data signifying number and character relationship on a phone
const vector<string> phonePad = {
    "",     // 0 
    "",     // 1 
    "ABC",  // 2
    "DEF",  // 3
    "GHI",  // 4
    "JKL",  // 5
    "MNO",  // 6
    "PQRS", // 7
    "TUV",  // 8
    "WXYZ"  // 9
};


void charCombinations(const string& num, string currentChars, int index) {
    // Base case, stop recursive function when index is as long as input number.
    if (index == num.length()) {
        cout << currentChars << endl;
        return;
    }

    // Digit at the current index
    int digit = num[index] - '0'; // char to integer conversion

    if (digit == 0 || digit == 1) {
        charCombinations(num, currentChars, index + 1);
        return;
    }

    // Letters for the current digit from phonepad vector
    const string& letters = phonePad[digit];

    // loop through letters
    for (int i = 0; i < letters.length(); i++) {
        charCombinations(num, currentChars + letters[i], index + 1);
    }
}

int main() {
    // test number
    string number;
    cout << "Enter a number: ";
    cin >> number;

    if (number.empty()) {
        cout << "Please enter a number." << endl;
        return 1;
    }

    cout << "Unique character combinations for " << number << ": " << endl;
    charCombinations(number, "", 0);

    return 0;
}