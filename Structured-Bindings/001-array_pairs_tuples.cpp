#include <iostream>
#include <tuple>
#include <utility>


using namespace std;

int main(){

   
    tuple<int, int, int> nums = {1, 2, 3};
    auto [a, b, c] = nums;

    cout<<a<<" "<<b<<" "<<c<<"\n";
    
    tuple<int, char, double> t = {1, 'a' , 2.0};
    auto [x, y, z] = t;

    cout<<x <<" "<<y<<" "<<z<<"\n";

    pair<int, string> p = {95, "pass"};
    auto [number, text] = p;

    cout<<number <<" "<<text<<"\n";

    return 0;
}