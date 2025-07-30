#include<iostream>
#include<stdexcept>

using namespace std;

int divide(int a, int b){
    if(b == 0)
        throw std::runtime_error("Cant divide by zero");

    return a/b;
}

int main(){

    try{
        cout<<divide(10, 0)<<"\n";
    }catch(const std::runtime_error& e){
        cout<<e.what()<<"\n";
    }

    return 0;
}