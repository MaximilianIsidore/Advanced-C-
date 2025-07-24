#include "config.hpp"
#include <iostream>
using namespace std;

void increment(){
    global_counter++;
    cout<<"global counter incremented \n";
}

void check_value(){
    cout<<"global counter value : "<<global_counter<<"\n";
}