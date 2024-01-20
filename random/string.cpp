#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string str;
    cin >> str;

    // Create a vector to store brr
    vector<char> brr;

    // Populate brr with even-indexed characters
    for (int i = 0; i < str.length(); i += 2) {
        brr.push_back(str[i]);
    }

    // Populate brr with odd-indexed characters
    for (int i = 1; i < str.length(); i += 2) {
        brr.push_back(str[i]);
    }

    // Use an unordered_map to store the frequency of each character in brr
    unordered_map<char, int> frequency;

    // Iterate over brr and update the frequency map
    for (char ch : brr) {
        frequency[ch]++;
    }

    // Find the first non-repeating character in brr
    for (char ch : brr) {
        if (frequency[ch] == 1) {
            cout << ch << endl;
            return 0;
        }
    }

    // If no non-repeating character is found, print -1
    cout << -1 << endl;

    return 0;
}
