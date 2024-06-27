#include "builder/Director.cpp"

int32_t main() {
    Director* dr1 = new Director(new EngineeringStudentBuilder());
    Director* dr2 = new Director(new MBAStudentBuilder());

    Student* engStudent = dr1->createStudent();
    Student* mbaStudent = dr2->createStudent();

    if (engStudent) {
        engStudent->show();
    } else {
        cout<<"\nengStudent is nullptr\n";
    }

    if (mbaStudent) {
        mbaStudent->show();
    } else {
        cout<<"\nmbaStudent is nullptr\n";
    }
    return 0;
}