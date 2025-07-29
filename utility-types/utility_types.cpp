#include <variant>
#include <string>
#include <iostream>
#include <optional>
#include <any>

std::optional<int> find_even(int x) {
    return (x % 2 == 0) ? std::make_optional(x) : std::nullopt;
}

int main() {
    std::variant<int, double, std::string> v;

    v = 42;                             // holds int
    std::cout << std::get<int>(v)<<"\n";     // prints 42

    v = 3.14;                          // holds double
    std::cout << std::get<double>(v)<<"\n";  // prints 3.14

    v = "hello";                       // holds std::string
    std::cout << std::get<std::string>(v)<<"\n"; // prints hello

    auto e = find_even(5);
    if (e) std::cout << *e << "\n";
    else   std::cout << "odd\n";

    std::any a = 42;
    a = std::string("hello");

    try {
        std::cout << std::any_cast<std::string>(a) << "\n";
    } catch (const std::bad_any_cast&) {
        std::cout << "Wrong type\n";
    }

    a.reset();
    if (!a.has_value()) std::cout << "empty\n";


    return 0;
}
