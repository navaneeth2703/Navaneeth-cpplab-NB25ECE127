#include <iostream>

using namespace std;

constexpr double PI = 3.14159265358979323846;

// 1. Cube (1 argument: side)
double volume(double side) {
    return side * side * side;
}

// 2. Cuboid (3 arguments: length, width, height)
double volume(double length, double width, double height) {
    return length * width * height;
}

// 3. Cylinder (2 arguments: radius, height)
double volume(double radius, double height) {
    return PI * radius * radius * height;
}

int main() {
    double side = 3.0;
    double length = 4.0, width = 5.0, height = 2.0;
    double radius = 2.5, cylHeight = 6.0;

    cout << "Cube volume:     " << volume(side) << '\n';
    cout << "Cuboid volume:   " << volume(length, width, height) << '\n';
    cout << "Cylinder volume: " << volume(radius, cylHeight) << '\n';

    return 0;
}