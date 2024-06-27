#ifndef _STUDENT_BUILDER_
#define _STUDENT_BUILDER_

#include "../common.hpp"
#include "../models/Student.hpp"
// import from header since it only needs ctor declaration at compile time

class StudentBuilder {
public:
    // This is one disadvantage: fields being duplicated across builder and concrete class
    
    //mandatory
    int rollNumber_; 
    
    //optional
    int age_;
    string name_;
    string fatherName_;
    string motherName_;

    vector<string> subjects_;

    StudentBuilder* setRollNumber(int rollNumber) {
        rollNumber_ = rollNumber;
        return this;
    }

    StudentBuilder* setAge(int age) {
        age_ = age;
        return this;
    }

    StudentBuilder* setName(string name) {
        name_ = name;
        return this;
    }

    StudentBuilder* setFatherName(string fatherName) {
        fatherName_ = fatherName;
        return this;
    }

    StudentBuilder* setMotherName(string motherName) {
        motherName_ = motherName;
        return this;
    }

    virtual StudentBuilder* setSubjects() = 0;

    Student* build() {
       Student* student = new Student(this);
       return student;
    }
};

#endif //_STUDENT_BUILDER_