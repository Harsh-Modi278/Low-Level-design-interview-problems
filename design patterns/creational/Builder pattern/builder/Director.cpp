#include "./EngineeringStudentBuilder.cpp"
#include "./MBAStudentBuilder.cpp"
#include "../Student.cpp"

template<typename B, typename T>
inline bool instanceof(const T* ptr) {
    // can ptr be dynamically casted to class B's pointer?
   return dynamic_cast<const B*>(ptr) != nullptr;
}

class Director {
    StudentBuilder* studentBuilder_;

    // directore class decides the order in which builders get called
    Student* createEngStudent() {
        return studentBuilder_->setRollNumber(1)->setAge(24)->setName("A")->setSubjects()->build();
    }

    Student* createMBAStudent() {
        return studentBuilder_->setRollNumber(2)->setAge(26)->setName("B")->setFatherName("hehe")->setSubjects()->build();
    }

public:
    Director(StudentBuilder* sb) {
        studentBuilder_ = sb;
    }

    Student* createStudent() {
        if (instanceof<EngineeringStudentBuilder>(studentBuilder_)) {
            return createEngStudent();
        } else if (instanceof<MBAStudentBuilder>(studentBuilder_)) {
            return createMBAStudent();
        } else {
            return nullptr;
        }
    }
};