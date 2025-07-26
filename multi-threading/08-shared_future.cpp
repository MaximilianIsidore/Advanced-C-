#include <iostream>
#include <future>

int getValue() {
    return 42;
}

void consumer(std::shared_future<int> sfut, int id) {
    std::cout << "Consumer " << id << " got " << sfut.get() << "\n";
}

int main() {
    std::future<int> fut = std::async(std::launch::async, getValue);
    std::shared_future<int> sfut = fut.share();

    std::thread c1(consumer, sfut, 1);
    std::thread c2(consumer, sfut, 2);

    c1.join();
    c2.join();
    return 0;
}
