#include "common.hpp"
#include "FileSystem.hpp"

class File: public FileSystem {
    string name_;
public:
    File(string name): name_(name) {};

    void ls() {
        cout<<"\nfile name: "<<name_<<" \n";
    }
};