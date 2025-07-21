#include<iostream>

using namespace std;

class MyClass {

private:
    int a=5, b= 10;

public:
    int getValue() const; // Can't modify *this
};

int MyClass::getValue() const{

    //this.a = 12;//causes error since a is a member of x

    return a+b;
}

consteval int getMax() { //consteval is only for functions, must be compile time
    return 100;
}

constinit int a = 10;//mutable but intialized at compile time, but only allowed in static or global scope.
    

int main(){

    const int num = 5; //constant immutable (compile time not required);
    cout<<num<<"\n";

    constexpr int sum = num * 5; //immutable , compile time if possible., can be used in function that need to be compile time if needed.
    cout<<"sum: "<<sum<<"\n";
    
    constexpr int max = getMax();
    cout<<max<<"\n";

    
    a = 20;
    cout<<a<<"\n";

    MyClass obj;
    int b = obj.getValue();

    return 0;
}