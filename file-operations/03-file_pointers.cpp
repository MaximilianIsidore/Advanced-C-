#include<iostream>
#include<fstream>
#include<string>

using namespace std;
//get stream pointers  seekg (move by pos from current), tellg(give current pointer)
//put stream pointers seekp(move by pos from current ), tellp (give current pointer)
int main(){
    std::ifstream file("example.txt");

    if (file.is_open()) {
        file.seekg(5); // Move to 6th byte
        char ch;
        file.get(ch);  // Read one character
        std::cout << "Character at position 6: " << ch << '\n';
        file.close();
    }

    return 0;

}