#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

//used to eliminate SFINAE and reduce compilation time.

template<typename T>
void print(const T& val) {
    if constexpr (std::is_same_v<T, std::string>) {
        std::cout << "String: " << val << "\n";
    } else if constexpr (requires { val.begin(); val.end(); }) {
        std::cout << "Container: ";
        for (const auto& item : val) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "Value: " << val << "\n";
    }
}


int main(){

    vector<int> arr = {1,2,3,4,5};
    string str = "hello world";

    print(arr);
    print(str);

    print("hh"); // classi c string i guess , so its not in string container.
    return 0;
}