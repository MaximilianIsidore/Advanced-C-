#include <iostream>
#include <memory>

using namespace std;

int main(){
    shared_ptr<int> sp = make_shared<int>(80);
    weak_ptr<int> wp = sp;

    if(auto locked = wp.lock()){ // weak ptr can be used only in lock
        cout<<"It now locked and acts like shared ptr, reference count "<<locked.use_count()<<"\n";
        cout<<"Value in locked : "<<*locked;
        auto new_ptr = sp;
        cout<<"\n new reference count : "<<sp.use_count();
    }
    cout<<"\n lock released  , reference count : "<<sp.use_count()<<"\n";
    cout<<"from weak ptr: "<< wp.use_count()<<"\n";

    return 0;
}