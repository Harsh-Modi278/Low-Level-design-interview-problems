#include <iostream>
using namespace std;

enum CarType
{
    BMW,
    AUDI
};

// --- Car models ---
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

// BWM and Audi also produce headlights
// --- Headlight models ---

class HeadLight{
public:
    virtual void show() = 0;
};

class BmwHeadLight: public HeadLight{
public:
    void show() {
        cout<<"bmw headlight\n";
    }
};

class AudiHeadLight : public HeadLight {
public:
    void show()
    {
        cout << "Audi headlight\n";
    }
};

// --- factories---
// Now if we are using factory method pattern, 
// we need to define another base factory which is specially responsible for headlights, 
// and two derived classes for BWM and Audi respectively. 
// total classes = 1 factory for headlight + 2 concrete class (for BMW and Audi) + 1 factor for Car + 2 concrete classes (for bmw and audi)
// total classes = 6
// problem: too many classes need to be created if the product family groups big. 
// solution: put the interfaces for those related products inside a single factory.

// abstract base class
class AbstractFactory {
public:
    virtual Car *createCar(string) = 0; // pure virtual fn
    virtual HeadLight* createHeadLight() = 0;
};

// responsible for creation of BMW car
class BMWFactory : public AbstractFactory
{
public:
    Car *createCar(string name) {
        return new Bmw(name);
    }

    HeadLight* createHeadLight() {
        return new BmwHeadLight();
    }
};

// responsible for creation of AUDI car
class AudiFactory : public AbstractFactory
{
public:
    Car *createCar(string name) {
        return new Audi(name);
    }

    HeadLight* createHeadLight() {
        return new AudiHeadLight();
    }
};

// https://navining.gitbook.io/gocpp/chapter-13-design-patterns/factory-pattern
// Abstract factory: a factory of factory
// used for series of related products
int32_t main()
{
    AbstractFactory *bmwfactory = new BMWFactory();
    AbstractFactory *audifactory = new AudiFactory();
    Car *p1 = bmwfactory->createCar("X6");
    Car *p2 = audifactory->createCar("A8");
    HeadLight *l1 = bmwfactory->createHeadLight();
    HeadLight *l2 = audifactory->createHeadLight();

    p1->show();
    p2->show();

    l1->show();
    l2->show();

    delete bmwfactory;
    delete audifactory;
    delete p1;
    delete p2;
    delete l1;
    delete l2;
    return 0;
}