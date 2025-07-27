#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

int main(){

    std::ofstream out_file("example.txt");

    if(out_file.is_open()){
        out_file<<"Hello world"<<"\n";
        out_file.close();
    }else{
        cout<<"Error opening the file\n";
    }

    std::ifstream infile("example.txt");
    string line;

    if(infile.is_open()){
        while(std::getline(infile, line)){
            cout<<line<<std::endl;
        }

        infile.close();
    }else{
            std::cerr << "Unable to open file for reading";    
    }

    return 0;
}