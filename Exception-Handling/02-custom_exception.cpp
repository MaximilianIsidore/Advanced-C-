#include <stdexcept>
#include <string>
#include<iostream>
#include<fstream>

class FileError : public std::runtime_error {
public:
    FileError(const std::string& filename, const std::string& msg)
      : std::runtime_error(filename + ": " + msg) {}
};

#include <fstream>
void readConfig(const std::string& file) {
    std::ifstream ifs(file);
    if (!ifs)
        throw FileError(file, "Cannot open file");
}


int main(){

    try{
        readConfig("non existent file");
    }catch(const FileError& e){
        std::cout<<e.what()<<"\n";
    }
    return 0;
}
