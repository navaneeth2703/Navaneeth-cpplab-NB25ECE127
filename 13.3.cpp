#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

long counter = 0;
mutex m;

void addSafe(int times) {
    lock_guard<mutex> lk(m); // locks once for the whole batch
    for (int i = 0; i < times; ++i) {
        ++counter; // protected critical section
    }
}

int main() {
    thread t1(addSafe, 100000);
    thread t2(addSafe, 100000);

    t1.join();
    t2.join();

    cout << "counter = " << counter << " (expected 200000)\n";
    return 0;
}