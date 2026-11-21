#include <array>
#include <iostream>

using namespace std;

class Complex {
private:
    double real = 0.0;
    double imag = 0.0;

public:
    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        cout << real;
        if (imag >= 0.0) {
            cout << " + " << imag << "i";
        } else {
            cout << " - " << (-imag) << "i";
        }
    }
};

int main() {
    array<Complex, 3> numbers;

    numbers[0].setData(3.0, 4.0);
    numbers[1].setData(1.5, -2.5);
    numbers[2].setData(-2.0, 5.0);

    for (size_t i = 0; i < numbers.size(); ++i) {
        cout << "z" << (i + 1) << " = ";
        numbers[i].display();
        cout << '\n';
    }

    return 0;
}