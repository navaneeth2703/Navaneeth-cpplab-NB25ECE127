#include <array>
#include <iostream>

using namespace std;

class Counter {
private:
    int value = 0;

public:
    void increment() {
        ++value;
    }

    void reset() {
        value = 0;
    }

    int get() const {
        return value;
    }
};

int main() {
    array<Counter, 3> counters; // array of 3 Counter objects, each starting at 0

    // Exercise individual counters
    counters[0].increment();
    counters[0].increment();
    counters[0].increment();

    counters[1].increment();
    counters[1].increment();

    counters[2].increment();

    cout << "After increments:\n";
    for (size_t i = 0; i < counters.size(); ++i) {
        cout << "Counter " << i << ": " << counters[i].get() << '\n';
    }

    // Reset counter 1 and increment it once more
    counters[1].reset();
    counters[1].increment();

    cout << "\nAfter resetting Counter 1 and incrementing once:\n";
    for (size_t i = 0; i < counters.size(); ++i) {
        cout << "Counter " << i << ": " << counters[i].get() << '\n';
    }

    return 0;
}