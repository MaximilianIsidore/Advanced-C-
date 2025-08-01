#include <type_traits>
#include <iostream>

using namespace std;

template<typename T>
concept Number = is_arithmetic_v<T>;//int, float, double ..

template <Number T>
T add(T a, T b){
    return a+b;
}

int main(){

    cout<<add(2, 5) <<"\n";
    cout<<add(2.0, 6.0)<<"\n";

    return 0;
}