#ifndef _STUDENT_
#define _STUDENT_

#include "common.hpp"
class StudentBuilder;

class Student {
    //mandatory
    int rollNumber_; 
    
    //optional
    int age_;
    string name_;
    string fatherName_;
    string motherName_;
    vector<string> subjects_;
public:
    // con: there can be multiple constructors depending on what fields are passed for init-ing the student object
    // fix: use builder design pattern
    // step by step creation of object
    Student(StudentBuilder* studentBuilder);

    void show();
};

#endif //_STUDENT_