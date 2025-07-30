#include <iostream>
#include <string>
#include <string_view>
//non owning string, no copy, only pointers and length

void greet(std::string_view name) {
    std::cout << "Hello, " << name << "!\n";
}

int main() {
    std::string fullName = "Mark Rob";
    greet(fullName);               // Works with std::string
    greet("Bob");                  // Works with string literal
    greet(fullName.substr(0, 5));  // can pass substrings

    std::string_view view = fullName;
    std::cout << view.substr(6) << "\n"; 
    
    //to copy the string from string view

    std::string new_str = std::string(fullName);
    std::cout<<new_str<<"\n";

    return 0;
}
