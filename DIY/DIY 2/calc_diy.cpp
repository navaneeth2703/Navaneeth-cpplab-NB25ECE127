#include <iostream>

using namespace std;

long long power(int base, int exp = 2) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    cout << "power(5) = " << power(5) << '\n';         // 25 (exp defaults to 2)
    cout << "power(2, 10) = " << power(2, 10) << '\n'; // 1024

    return 0;
}