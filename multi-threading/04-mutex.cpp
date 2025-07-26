#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

std::mutex mtx;
int counter = 0;

void increment(){

    while(counter <= 1000){
        mtx.lock();
        counter++;
        cout<<"counter : "<<counter<<" from "<<this_thread::get_id()<<"\n";
        mtx.unlock();
    }
    cout<<"Thread from "<<this_thread::get_id()<<" ended\n";
}
int main(){

    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    return 0;
}