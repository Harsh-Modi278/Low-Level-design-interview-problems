#include<iostream>
#include <models/ParkingLot.h>
using namespace std;

int main() {

    vector<Level*> floors;
    map<SpotSize, vector<ParkingSpot *>> l1ParkingSports;
    l1ParkingSports[twoWheeler] = {new ParkingSpot(1, twoWheeler), new ParkingSpot(2, twoWheeler)};
    l1ParkingSports[small] = {new ParkingSpot(1, small), new ParkingSpot(2, small)};
    l1ParkingSports[medium] = {new ParkingSpot(1, medium), new ParkingSpot(2, medium), new ParkingSpot(3, medium)};
    l1ParkingSports[large] = {new ParkingSpot(1, large), new ParkingSpot(2, large), new ParkingSpot(3, large)};

    Level *level1 = new Level(1, l1ParkingSports);
    ParkingLot* parkingLot = ParkingLot::getInstance({level1});

    Vehicle* v1 = new Vehicle('GJ6-01', twoWheeler);

    parkingLot->ParkVehicle(v1);
    return 0;
}