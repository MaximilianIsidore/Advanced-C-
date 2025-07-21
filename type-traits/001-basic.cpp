#include <iostream>

namespace my_traits {

template<typename T, typename U>
struct is_same {
    static constexpr bool value = false;
};

template<typename T>
struct is_same<T, T> {
    static constexpr bool value = true;
};

} // namespace my_traits

int main() {
    std::cout << std::boolalpha;
    std::cout << "is_same<int, int>::value = " << my_traits::is_same<int, int>::value << "\n";     // true
    std::cout << "is_same<int, float>::value = " << my_traits::is_same<int, float>::value << "\n"; // false

    return 0;
}
