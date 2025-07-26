#include <iostream>
#include <thread>

int main(){
    unsigned cores = std::thread::hardware_concurrency();
    std::cout << "CPU cores available: " << cores << "\n";
    return 0;
}