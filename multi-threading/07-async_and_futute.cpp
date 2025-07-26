#include <iostream>
#include <future>
#include <chrono>

int calculateSquare(int x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    return x * x;
}

int main() {
    // Launch asynchronously
    std::future<int> fut = std::async(std::launch::async, calculateSquare, 5);

    std::cout << "Doing other work...\n";
    // Get blocks until calculateSquare returns
    int result = fut.get();
    std::cout << "Square: " << result << "\n";
    return 0;
}
