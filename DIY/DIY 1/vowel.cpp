#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isVowel(unsigned char ch) {
    char lower = static_cast<char>(tolower(ch));
    return lower == 'a' || lower == 'e' || lower == 'i' ||
           lower == 'o' || lower == 'u';
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    if (!getline(cin, s)) {
        return 0;
    }

    int vowels = 0;
    int consonants = 0;

    for (unsigned char ch : s) {
        if (isalpha(ch)) {
            if (isVowel(ch)) {
                ++vowels;
            } else {
                ++consonants;
            }
        }
    }

    cout << "Vowels: " << vowels << '\n';
    cout << "Consonants: " << consonants << '\n';

    return 0;
}