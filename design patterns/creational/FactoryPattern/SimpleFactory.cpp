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

class SimpleFactory {

public:
    Car* createCar(CarType carType) {
        if (carType == CarType::AUDI) {
            return new Bmw("X1");
        } else if (carType == CarType::BMW) {
            return new Audi("A6");
        } else {
            return nullptr;
        }
    }
};

int32_t main() {
    SimpleFactory *factory = new SimpleFactory();
    Car * car1 = factory->createCar(CarType::BMW);
    Car *car2 = factory->createCar(CarType::AUDI);

    car1->show();
    car2->show();

    // con: doesn't meet open closed principle
    // should be open for extension, closed for modification
    // but everytime we have to create a new carType, we have to modify the factory

    // The simple factory pattern use a single factory class to produce all the products.
    // It is simple, but it doesn't meet the open-close principle.
    // If we want to add new products to the factory, we need to always modify the interface, 
    // which is not a good software design.
    return 0;
}