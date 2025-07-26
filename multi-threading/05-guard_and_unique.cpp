#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

std::mutex mtx;

int count1{}, count2{};

void mutiple_incrementer(){

    while(count1 < 100){
        std::lock_guard<std::mutex> guard(mtx); //scope based
        count1++;
        cout<<"Count1 from "<<this_thread::get_id() <<" is "<< count1<<"\n";
    }

    std::unique_lock<std::mutex> lock(mtx, std::defer_lock); //more flexible can be locked and unlocked on need
    while(count2 < 100){// this is not protected be careful not safe approach race condition can occur.
        lock.lock();
        count2++;
        cout<<"Count2 from "<<this_thread::get_id() <<" is "<< count2<<"\n";
        lock.unlock();
    }
}

int main(){

    thread t1(mutiple_incrementer);
    thread t2(mutiple_incrementer);

    t1.join();
    t2.join();

    return 0;
}