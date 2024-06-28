#ifndef _PERSON_H_
#define _PERSON_H_

#include "common.hpp"

class Person {
    int age_;
    string name_;
public:
    Person(int age, string name) : age_(age), name_(name) {};

    string getName() {
        return name_;
    }
};

#endif //_PERSON_H_