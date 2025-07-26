#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

std::atomic<int> counter{0};

void inc() {
    for (int i = 0; i < 1'000; ++i){

        ++counter;
        cout<<"counter from "<<this_thread::get_id()<<" is "<<counter<<"\n";
    }
}

int main(){

    thread t1(inc);
    thread t2(inc);

    t1.join();
    t2.join();

    return 0;
}
