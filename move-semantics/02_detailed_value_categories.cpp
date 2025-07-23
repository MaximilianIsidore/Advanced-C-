#include <iostream>
#include <string>
#include <utility>

using namespace std;

struct MyString{

    string value;

    MyString(const string& val) : value(val){
        cout<<"Constructed from lvalue\n";
    }

    MyString(const string&& val) : value(std::move(val)){
        cout<<"Constructed from rvalue\n";
    }

    MyString(const MyString& other){
        value = other.value;
        cout<<"[MyString] Copy constructed\n";
    }

    MyString( MyString&& other) noexcept{
        value = std::move(other.value);
        cout << "[MyString] Move constructed\n";
    }

    ~MyString() {
        std::cout << "[MyString] Destroyed\n";
    }
};

void take(const MyString& s) {
    std::cout << "[Function] Took lvalue reference (const MyString&)\n";
}

void take(MyString&& s) {
    std::cout << "[Function] Took rvalue reference (MyString&&)\n";
}

MyString getName(){
    std::cout << "[getName()] Returning prvalue (temporary MyString)\n";
    return MyString("Hello");
}

int main(){

    std::cout << "\n--- Case 1: lvalue ---\n";
    MyString name("Advanced Cpp"); // Construct from rvalue
    take(name);              // Should call const lvalue ref version

    std::cout << "\n--- Case 2: xvalue via std::move ---\n";
    take(std::move(name));   // Should call rvalue ref version

    std::cout << "\n--- Case 3: prvalue from function return ---\n";
    take(getName());         // Should call rvalue ref version (prvalue)

    std::cout << "\n--- Case 4: prvalue directly in constructor ---\n";
    MyString temp = MyString("Rain"); // prvalue created, moved or elided

    std::cout << "\n--- Case 5: lvalue to lvalue constructor ---\n";
    MyString copy = name;    // Should call copy constructor

    std::cout << "\n--- Case 6: xvalue to move constructor ---\n";
    MyString moved = std::move(temp); // Should call move constructor

    std::cout << "\n--- End of main ---\n";

    return 0;
}