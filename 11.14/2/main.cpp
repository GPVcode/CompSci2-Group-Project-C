#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

// Recursive function to generate all character combinations for a number part
void charCombinations(const string& num, string currentChars, int index, vector<string>& combinations) {
    // Base case: if we've processed the whole part of the number
    if (index == num.length()) {
        combinations.push_back(currentChars);
        return;
    }

    // Digit at the current index
    int digit = num[index] - '0';
    // Letters for the current digit from phonepad vector
    const string& letters = phonePad[digit];

    // Skip the digit if it has no letters (like 0 or 1)
    if (digit == 0 || digit == 1) {
        charCombinations(num, currentChars, index + 1, combinations);
    } else {
        // Recursively add each letter
        for (char letter : letters) {
            charCombinations(num, currentChars + letter, index + 1, combinations);
        }
    }
}

// Function to split the phone number into parts
vector<string> splitPhoneNumber(const string& phoneNumber) {
    // store sections of the phone number
    vector<string> parts;
    string part = "";

    // loop through characters in phone number
    for(int i = 0; i < phoneNumber.length(); i++){
        if(phoneNumber[i] == '-'){
            // end of part is reached if we se a dash ('-')
            parts.push_back(part);
            part = "";
        } else {
            // as long as char is number, add characters to current phone part
            part += phoneNumber[i];
        }
    }

    // add the last part of phone number since numbers dont end with a dash
    if(!part.empty()){
        parts.push_back(part);
    }

    return parts;
}

// Function to generate all word sequences for the entire phone number
void generateWordSequences(const string& phoneNumber) {
    // First split phone number into parts (e.g., 555-555-5555 -> {"555", "555", "555"})
    vector<string> parts = splitPhoneNumber(phoneNumber);
    // 2d vector to store all combinations per parts
    vector<vector<string>> allCombinations;

    // For each part, generate combinations of letters
    for (int i = 0; i < parts.size(); i++) {
        // temp storage of combinations
        vector<string> combinations;
        // find character combinations.
        charCombinations(parts[i], "", 0, combinations);
        // push cobinations foudn into main combinations 2d vector.
        allCombinations.push_back(combinations);
    }

    // Combine all parts into full word sequences
    for (int i = 0; i < allCombinations[0].size(); i++) {
        for (int j = 0; j < allCombinations[1].size(); j++) {
            for (int k = 0; k < allCombinations[2].size(); k++) {
                cout << allCombinations[0][i] << " " << allCombinations[1][j] << " " << allCombinations[2][k] << endl;
            }
        }
    }
}

int main() {
    string phoneNumber;
    cout << "Enter a phone number using format (555-555-5555): ";
    cin >> phoneNumber;

    cout << "Possible word sequences for " << phoneNumber << " are: " << endl;
    generateWordSequences(phoneNumber);

    return 0;
}
