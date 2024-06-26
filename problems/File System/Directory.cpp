#include "common.hpp"
#include "FileSystem.hpp"

class Directory: public FileSystem {
    string name_;
    vector<FileSystem*> fileSystemList;
public:
    Directory(string name): name_(name) {
        fileSystemList.clear();
    };

    void add(FileSystem* fsObj) {
        fileSystemList.push_back(fsObj);
    }

    void ls() {
        cout<<"\nDirectory name: "<<name_<<" \n";
        for (FileSystem* &fs:fileSystemList) {
            fs->ls();
        }

        // If composite design pattern hadn't been used then Directory and File would have been
        // two separate classes not related to each other by their parent class: FileSystem
        // In that case, the recursion to list all entries in a directory will require
        // if (fs instanceOf File) conditional statements
    }
};