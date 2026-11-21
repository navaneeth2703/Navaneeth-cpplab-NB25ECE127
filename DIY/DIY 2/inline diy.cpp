#include <iostream>

using namespace std;

// 1. Smallest of two ints
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// 2. Smallest of three ints (reuses the 2-arg overload)
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "minVal(10, 4) = " << minVal(10, 4) << '\n';
    cout << "minVal(15, 3, 9) = " << minVal(15, 3, 9) << '\n';

    return 0;
}