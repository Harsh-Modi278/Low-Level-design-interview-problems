#include "Floor.h"

class ParkingLot {
    int parkingLotId;
protected:
    ParkingLot(int id, int cntfloors, int slotsPerFloor);

public:
    vector<Floor*> floors;
    ParkingLot(ParkingLot& p) = delete;
    void operator=(const ParkingLot&) = delete;
    static ParkingLot *getParkingLot(int id, int cntfloors, int slotPerFloot);
    static ParkingLot* parkingLot_;

    void addFloor(Floor* newFloor);
    Slot* park(Vehicle*);
};
