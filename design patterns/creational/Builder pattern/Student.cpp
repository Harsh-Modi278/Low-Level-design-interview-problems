#include "models/Student.hpp"
#include "builder/StudentBuilder.cpp"

Student::Student(StudentBuilder* studentBuilder) {
    rollNumber_ = studentBuilder->rollNumber_;
    age_ = studentBuilder->age_;
    name_ = studentBuilder->name_;
    fatherName_ = studentBuilder->fatherName_;
    motherName_ = studentBuilder->motherName_;
    subjects_ = studentBuilder->subjects_;
}

void Student::show() {
    cout<<"\nroll number: "<<rollNumber_<<" \n"<<"age: "<<age_<<" \n"<<"name: "<<name_<<" \n"<<"father name: "<<fatherName_<<" \n"<<"mother name: "<<motherName_<<" \n";
    cout<<"subjects: ";
    for (string& s: subjects_) cout<<s<<" ";
    cout<<"\n";
}