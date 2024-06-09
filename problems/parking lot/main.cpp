#include "models/ParkingLot.h"

int32_t main() {
    string input = "";
    ParkingLot* parkingLot = nullptr;
    Vehicle* car = new Vehicle(1, "white", VehicleType::CAR);

    while (input != "exit") {
        cin>>input;

        if (input == "create_parking_lot") {
            int parkingLotId, floors, slotsPerFloor;
            cin>>parkingLotId>>floors>>slotsPerFloor;
            parkingLot = ParkingLot::getParkingLot(parkingLotId, floors, slotsPerFloor);
        }
        else if (input == "park_vehicle") {
            parkingLot->park(car);
        }
        else if(input == "display_free_slots") {
            for (auto &vehicleType : vehicleTypesList) {
                for (int i=0;i<(int)(parkingLot->floors).size();i++) {
                    parkingLot->floors[i]->displayFreeSlots(vehicleType);
                }
            }
        }
        else if (input == "display_occupied_slots") {
            for (auto &vehicleType : vehicleTypesList) {
                for (int i = 0; i < (int)(parkingLot->floors).size(); i++) {
                    parkingLot->floors[i]->displayOccupiedSlots(vehicleType);
                }
            }
        } 
        else if (input == "park") {
            parkingLot->park(car);
        }
        else if (input == "unpark") {
            //TODO
        }
        else if (input == "exit") {
            break;
        }
        else {
            cout<<"invalid input, please try again!\n";
        }
    }
    return 0;
}