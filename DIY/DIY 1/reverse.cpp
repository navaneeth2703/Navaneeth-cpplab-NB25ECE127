#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    cout << "Enter a sentence: ";
    if (!getline(cin, line)) {
        return 0;
    }

    istringstream iss(line);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    for (size_t i = words.size(); i-- > 0;) {
        cout << words[i];
        if (i > 0) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}