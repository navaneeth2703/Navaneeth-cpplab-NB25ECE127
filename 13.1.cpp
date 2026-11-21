#include <iostream>
#include <memory>
#include <string>

using namespace std;

constexpr double PI = 3.14159265358979323846;

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    double r;
    explicit Circle(double r) : r(r) {}
    double area() const override {
        return PI * r * r;
    }
};

struct Square : Shape {
    double s;
    explicit Square(double s) : s(s) {}
    double area() const override {
        return s * s;
    }
};

unique_ptr<Shape> makeShape(const string& kind) {
    if (kind == "circle") {
        return make_unique<Circle>(2.0);
    }
    if (kind == "square") {
        return make_unique<Square>(3.0);
    }
    return nullptr;
}

int main() {
    auto a = makeShape("circle");
    auto b = makeShape("square");

    if (!a || !b) {
        cerr << "Invalid shape kind\n";
        return 1;
    }

    cout << "area a = " << a->area() << ", area b = " << b->area() << '\n';
    return 0;
}