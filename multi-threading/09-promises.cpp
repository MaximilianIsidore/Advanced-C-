#include <iostream>
#include <thread>
#include <future>

void producer(std::promise<std::string> p) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_value("Data ready");
}

void consumer(std::future<std::string> f) {
    std::string data = f.get();  // blocks until set_value
    std::cout << "Consumer received: " << data << "\n";
}

int main() {
    std::promise<std::string> prom;
    std::future<std::string> fut = prom.get_future();

    std::thread prod(producer, std::move(prom));
    std::thread cons(consumer, std::move(fut));

    prod.join();
    cons.join();
    return 0;
}
