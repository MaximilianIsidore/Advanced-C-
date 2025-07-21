#include <iostream>
using namespace std;

template<typename T>
void print(T first){
    cout<<first<<"\n";
}

template <typename T, typename ... Rest> //without fold expression , uses recursion
void print(T first, Rest ... rest){
    cout<<first<<"\n";
    print(rest ...);
}

template<typename ... Args>
void fold_print(Args ... args){
    (cout<<...<<args);
}

int main(){

    print(1,2, 3, "...", "Hello, world!");

    fold_print(1,2, 3, "...", "Hello, world!");

    return 0;
}