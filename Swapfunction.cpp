 #include<iostream>
 using namespace std;
 void SwapRef(int&a,int&b)
 {
    int t=a;a=b;b=t;
 } 
 void swapPtr(int*a,int*b)
 {int t=*a;*a=*b;*b=t;}
 int main() { 
    int x=10,y=20;
    SwapRef(x,y);
    cout<<"After SwapRef:x="<< x <<"y="<< y <<endl;
    swapPtr(&x,&y);
    cout << "Äfter swapPtr:x=" << x << "y=" << y << endl;
    int &alias=x;
    alias=99;
    cout<<"x via alias="<<x<<endl;
    return 0;
 }
    
 