#include<iostream>
using namespace std;
class Tracer {
    int id;
    public:
    Tracer(int i):id(i) {cout<<"constructor#"<<id<< endl;}
~Tracer() {cout<<"Destructor#"<<id<<endl;} 
};
int main() {
    cout<<"Enter block\n";
    { Tracer a(1),b(2);cout<<"....working....\n";}
    cout<<"Left Block\n";
    return 0;
}
    
    

