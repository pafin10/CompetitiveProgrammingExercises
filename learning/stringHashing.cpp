#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to calculate the hash value of a string
// would normally involve %m
size_t hashString(const string& str) {
    size_t hashValue = 0;
    for (char ch : str) {
        hashValue = hashValue * 31 + ch; // A simple hash function, you can use a more sophisticated one
    }
    return hashValue;
}

// Function to compare a string with a pattern using hashing
void compareWithString(const string& input, const string& pattern) {
    unordered_map<size_t, string> patternHashTable;

    // Hash the pattern
    size_t patternHash = hashString(pattern);
    patternHashTable[patternHash] = pattern;

    // Hash the substrings of the input string and compare with the pattern
    for (int i = 0; i <= input.length() - pattern.length(); ++i) {
        string substring = input.substr(i, pattern.length());
        size_t substringHash = hashString(substring);
        if (patternHashTable.find(substringHash) != patternHashTable.end()) {
            // Potential match found, perform full string comparison
            if (patternHashTable[substringHash] == substring) {
                cout << "Pattern found at index " << i << endl;
            }
        }
    }
}

int main() {
    string input = "abracadabra";
    string pattern = "cad";

    compareWithString(input, pattern);

    return 0;
}
