#include <iostream>

using namespace std;

class Rectangle {
private:
    double length = 0.0;
    double width = 0.0;

public:
    Rectangle() = default;

    Rectangle(double l, double w) {
        setLength(l);
        setWidth(w);
    }

    bool setLength(double l) {
        if (l < 0.0) {
            cout << "Invalid length (" << l << "): must be non-negative.\n";
            return false;
        }
        length = l;
        return true;
    }

    bool setWidth(double w) {
        if (w < 0.0) {
            cout << "Invalid width (" << w << "): must be non-negative.\n";
            return false;
        }
        width = w;
        return true;
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2.0 * (length + width);
    }
};

int main() {
    Rectangle r;
    r.setLength(5.0);
    r.setWidth(3.0);

    cout << "Area:      " << r.area() << '\n';
    cout << "Perimeter: " << r.perimeter() << '\n';

    // Rejected negative inputs keep previous valid values
    r.setLength(-4.0);
    r.setWidth(-2.0);

    cout << "After invalid input -> Area: " << r.area()
         << ", Perimeter: " << r.perimeter() << '\n';

    return 0;
}