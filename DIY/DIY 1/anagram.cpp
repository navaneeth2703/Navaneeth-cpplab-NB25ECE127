#include <array>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool areAnagramsByFrequency(const string& a, const string& b) {
    if (a.size() != b.size()) {
        return false;
    }

    array<int, 256> freq{};

    for (unsigned char ch : a) {
        ++freq[static_cast<unsigned char>(tolower(ch))];
    }

    for (unsigned char ch : b) {
        --freq[static_cast<unsigned char>(tolower(ch))];
    }

    for (int count : freq) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string first, second;
    cout << "Enter two words: ";
    if (!(cin >> first >> second)) {
        return 0;
    }

    if (areAnagramsByFrequency(first, second)) {
        cout << "Anagram\n";
    } else {
        cout << "Not an anagram\n";
    }

    return 0;
}