#include <iostream>
#include <memory>

using namespace std;

class Dummy{
    public:
        Dummy(){
            cout<<"dummy obj created\n";
        }

        void check(){
            cout<<"Yes i am callable\n";
        }
};

int main(){

    unique_ptr<int> int_ptr = make_unique<int>(45);
    cout<<"Vlaue in int_ptr : "<< *int_ptr<<"\n";
    cout<<"Adress in int_ptr : "<< int_ptr.get()<<"\n";
    cout<<"Adress of int_ptr : "<<&int_ptr<<"\n";

    auto *copy_ptr = &int_ptr;
    cout<<**copy_ptr<<"\n";

    Dummy *dummy = new Dummy();
    auto *ptr_dummy  = &dummy;

    (*dummy).check();
    (**ptr_dummy).check();

    unique_ptr<Dummy> u_dummy = make_unique<Dummy>();
    u_dummy->check();

    auto * u_dummy_ptr = &u_dummy;
    (**u_dummy_ptr).check();

    auto new_ptr = std::move(u_dummy);//ownership transfered
    cout<<u_dummy.get()<<"\n";//should show 0
    u_dummy->check();//should fail but somehow works in my machine lol
    if (!u_dummy) std::cout << "Original unique_ptr is now null." << std::endl;

    new_ptr->check();

    return 0;
}