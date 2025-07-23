#include <iostream>
using namespace std;

int main(){
    int x = 5;     // x is an lvalue, 5 is rvalue
    x = 10;        // valid: x is on the left side
    int* p = &x;   // valid: you can take address of x

    cout<<"lvalue x : "<<x<<"\n";
    


    return 0;
}