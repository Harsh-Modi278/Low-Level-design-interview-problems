#include <iostream>
using namespace std;

enum CarType
{
    BMW,
    AUDI
};

class Car
{
public:
    Car(string name) : _name(name) {}
    virtual void show() = 0;

protected:
    string _name;
};

class Bmw : public Car
{
public:
    Bmw(string name) : Car(name) {}
    void show()
    {
        cout << "BMW: " << _name << endl;
    }
};

class Audi : public Car
{
public:
    Audi(string name) : Car(name) {}
    void show()
    {
        cout << "Audi: " << _name << endl;
    }
};

// abstract base class
class Factory
{
public:
    virtual Car *createCar(string) = 0; // pure virtual fn
};

// responsible for creation of BMW car
class BMWFactory: public Factory {
public:
    Car* createCar(string name) {
        return new Bmw(name);
    }
};

// responsible for creation of AUDI car
class AudiFactory : public Factory {
public:
    Car *createCar(string name)
    {
        return new Audi(name);
    }
};

int32_t
main()
{
    Factory *bmwfactory = new BMWFactory();
    Factory *audifactory = new AudiFactory();
    Car *p1 = bmwfactory->createCar("X6");
    Car *p2 = audifactory->createCar("A8");

    p1->show();
    p2->show();

    // a factory is responsible for creation of one product
    // If a new brand of car is added, 
    // we can define a new factory class which inherits from Factory, and provide its own createCar() interface.
    return 0;
}