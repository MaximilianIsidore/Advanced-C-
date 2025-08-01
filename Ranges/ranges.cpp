#include<iostream>
#include<Ranges>
#include<vector>

using namespace std;

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    auto even_squares = arr | std::views::filter([](int x){ return x%2 == 0; })  |
                        std::views::transform([](int x){ return x*x; });

    for(auto num : even_squares){
        cout<<num<<" ";
    }
    cout<<endl;
    
    return 0;
}