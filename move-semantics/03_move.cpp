#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Dummy{

    public:
        string value;

        Dummy(const string& value) : value(value){
            cout<<"constructor created \n";
        }
};

int main(){

   string name =  string("hello");
   cout<<"Name: "<<name<<"\n";
   cout<<"whats does std::move return? " <<std::move(name)<<"\n";
   cout<<"old name : "<<name <<"\n";//the value in name changes to null after its gets assigned.

//    string intermediate = name;
//    cout<<"old name : "<<name <<"intermediate value" << intermediate<<"\n";

   string new_name = std::move(name);
   cout<<"old name : "<<name <<"new name : "<<new_name<<"\n";

   Dummy new_str("Good day");
   cout<<new_str.value<<"\n";

   //cout<<std::move(new_str);
   Dummy new_dummy = std::move(new_str);

   cout<<"old obj value : "<<new_str.value <<" new obj value : "<< new_dummy.value<<"\n";

    return 0;
}