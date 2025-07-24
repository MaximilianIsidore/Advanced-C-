
#include "config.hpp"
#include "check_value.hpp"
using namespace std;

int main(){
    increment();
    check_value();

    global_counter = 25;
    check_value();

    return 0;
}