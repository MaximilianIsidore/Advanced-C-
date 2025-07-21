#include<iostream>
#include<vector>
#include<type_traits>
#include<set>
using namespace std;

//detect contanior is iteratable or not
template <typename T, typename = void>
struct is_iterable : std::false_type{};

template <typename T>
struct is_iterable < T, std::void_t<
    decltype(std::begin(std::declval<T>())),
    decltype(std::end(std::declval<T>()))
>> : std::true_type {};

template<typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;

// Printer
template<typename T>
std::enable_if_t<!is_iterable_v<T>>
print_one(const T& val) {
    std::cout << val;
}

template<typename T>
std::enable_if_t<is_iterable_v<T>>
print_one(const T& container) {
    std::cout << " [ ";
    for (const auto& item : container) {
        print_one(item);  // recursive
        std::cout << " ";
    }
    std::cout << "] ";
}

template<typename... Args>
void printAll(Args&&... args) {
    (print_one(std::forward<Args>(args)), ...);  // Fold expression with custom handler
}

int main(){

    printAll(42, std::vector<int>{1,2,3}, "ok", std::set<std::string>{"a", "b"});
    return 0;
}