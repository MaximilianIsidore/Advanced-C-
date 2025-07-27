#include<iostream>
#include<fstream>
using namespace std;

int main(){

    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);

    if (file.is_open()) {
        file << "Adding new content.\n"; // write
        file.seekg(0); // go back to beginning
        std::string content;
        while (std::getline(file, content)) {
            std::cout << content << std::endl; // read
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }

    return 0;
}