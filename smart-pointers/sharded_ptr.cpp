#include <iostream>
#include <memory>

using namespace std;

int main(){

    shared_ptr<int> ptr1 = make_shared<int>(100);
    cout<<"Reference count before : "<< ptr1.use_count()<<"\n";
    shared_ptr<int> ptr2 = ptr1;

    cout<<"value in ptr1 : "<< *ptr1 << " value in ptr2 : "<< *ptr2<<"\n";
    cout<<"Reference count : "<< ptr1.use_count() << " "<<ptr2.use_count()<<"\n";

    *ptr2 = 200;
    cout<<"value in ptr1 : "<< *ptr1 << " value in ptr2 : "<< *ptr2<<"\n";
    
    return 0;
}