#include<iostream>
#include <map>
#include <string>

using namespace std;

struct response{
    int statusCode;
    string message;
};

response networkStatus(){
    return {200, "successful"};
}

int main(){

    auto [code, msg] = networkStatus();

    cout<<code <<" "<<msg<<"\n";

    map<char, int>  mp = {{'a', 5}, {'b', 10}};

    for(const auto& [alpha , count] : mp){
        cout<<alpha <<" "<<count<<"\n";
    }
    return 0;
}