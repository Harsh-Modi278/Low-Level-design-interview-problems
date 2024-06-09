#include <models/Vehicle.h>

class Vehicle
{
private:
    ParkingSpot *spot;
    string numberPlate;
    VehicleCategory vehicleCategory;

public:
    Vehicle(string number, VehicleCategory vehicleCategory)
    {
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

    void removeVehicle() {
        spot->removeVehicle();
    }
};