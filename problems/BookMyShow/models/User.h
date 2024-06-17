#ifndef USER_H
#define USER_H

#include "common.h"

class User {
    int id_;
    string name_;
    //etc
public:
    User(int id, string name): id_(id), name_(name) {};
};

#endif //USER_H