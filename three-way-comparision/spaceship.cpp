#include<iostream>
using namespace std;

struct point{
    int x, y;

    auto operator<=>(const point&) const =default;
};

int main(){

    point a ={1,3};
    point b = {1,3};
    point c={3, 5};

    cout<<std::boolalpha;
    cout<<(a==b)<<"\n";
    cout<<(a<c)<<"\n";
    return 0;
}