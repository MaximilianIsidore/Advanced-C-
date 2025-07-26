#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Tick\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Tock\n";
    return 0;
}
