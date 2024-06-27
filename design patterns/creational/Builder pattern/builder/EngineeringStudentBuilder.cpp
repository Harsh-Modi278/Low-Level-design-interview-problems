#include "StudentBuilder.cpp"

class EngineeringStudentBuilder : public StudentBuilder {
public:
    StudentBuilder* setSubjects() {
        subjects_.clear();
        subjects_.push_back("DSA");
        subjects_.push_back("OS");
        subjects_.push_back("Computer Architecture");

        return this;
    }
};