#include<iostream>
#include <ostream>
#include<type_traits>

using namespace std;

template<typename T>
concept Streamable = requires(std::ostream& os, T a){
    {os<<a} -> std::same_as<std::ostream&>;
};

template <Streamable T>
void print(T val){
    std::cout<<val<<"\n";
}

int main(){
    print(35);
    print("hi");

    return 0;
}