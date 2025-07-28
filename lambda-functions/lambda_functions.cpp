#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int b = 10;
    int c = 15;

    auto add = [](int a, int b){ return a + b;};

    cout<<"Basic lambda add function : "<<add(10,12)<<"\n";

    auto add_ref = [&](){return a+b+c;};
    cout<<"add function that uses capture by reference capture list : "<<add_ref()<<"\n";

    auto add_val = [=](){ return c+b;};
    cout<<"add function that uses capture by value : "<<add_val()<<"\n";
    
    return 0;
}