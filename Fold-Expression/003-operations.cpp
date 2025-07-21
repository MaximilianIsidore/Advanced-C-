#include<iostream>
#include<type_traits>
using namespace std;

//unary
template<typename... Args>
void negate_all(Args&&... args) {
    ((std::cout << !args << " "), ...);
}

//binary
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

template<typename... Args>
auto product(Args... args) {
    return (args * ...);
}

template<typename... Args>
bool all_true(Args... args) {
    return (args && ...);
}

//assignments
template<typename T, typename... Args>
void assign_all(T& first, Args&... rest) {
    ((rest = first), ...);
}

template<typename... Args>
void reset(Args&... args) {
    ((args = 0), ...);
}

//comma operator
template<typename... Args>
void print_all(Args&&... args) {
    ((std::cout << args << " "), ...);  // left fold with comma
}

// template<typename... Callables>
// auto call_all(Callables&&... funcs) {
//     return [=](auto&&... args) {
//         (funcs(std::forward<decltype(args)>(args)...), ...);
//     };
// }



//relational operation with pointers
template<typename... Args>
bool all_non_null(Args... args) {
    return (... && (args != nullptr));
}


int main(){

   cout<<sum(1,2,3)<<"\n";

    int a = 5, b= 10;
    reset(a, b);
    
    cout<<a<<" "<<b;

    return 0;
}


