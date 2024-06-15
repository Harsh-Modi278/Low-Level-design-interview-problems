#include "models/common.h"
#include "models/Vehicle.h"

class VehicleInventoryManagement {
    vector<Vehicle*> vehicles_;
public:
    VehicleInventoryManagement(vector<Vehicle *> vehicles): vehicles_(vehicles){};

    vector<Vehicle *> getVehicles(VehicleType vType) {
        ///filtering
        vector<Vehicle*> vehicles;
        for (Vehicle* v:vehicles_) {
            if (v->isAvailable() && v->getVehicleType() == vType) {
                vehicles.push_back(v);
            }
        }
        return vehicles;
    }

    void addVehicles(vector<Vehicle *> vehiclesToAdd) {
        for (Vehicle* v:vehiclesToAdd) {
            vehicles_.push_back(v);
        }
    }
};