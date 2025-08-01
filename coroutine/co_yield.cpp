#include <iostream>
#include <generator>  // C++23 only!

std::generator<int> numbers(int n) {
    for (int i = 0; i <= n; ++i)
        co_yield i;  // yield the number and pause
}

int main() {
    for (int x : numbers(3)) {
        std::cout << x << " ";
    }

    return 0;
}
