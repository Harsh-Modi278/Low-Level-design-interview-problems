#include "StudentBuilder.cpp"

class MBAStudentBuilder : public StudentBuilder {
public:
    StudentBuilder* setSubjects() {
        subjects_.clear();
        subjects_.push_back("Micro Economics");
        subjects_.push_back("Operations Management");
        subjects_.push_back("Business Studies");

        return this;
    }
};