#include <iostream>
#include <sstream>

using namespace std;

class ParkingSpot;

enum VehicleCategory
{
    TwoWheeler,
    Hatchback,
    Sedan,
    SUV,
    Bus
};

class Vehicle
{
private:
    ParkingSpot *spot;
    string numberPlate;
    VehicleCategory vehicleCategory;

public:
    Vehicle(string number, VehicleCategory vehicleCategory) {
        numberPlate = number;
        vehicleCategory = vehicleCategory;
    }

    VehicleCategory getCategory() const
    {
        return vehicleCategory;
    }

    void parkInSpot(ParkingSpot *ps)
    {
        spot = ps;
    }

    void removeVehicle();
};