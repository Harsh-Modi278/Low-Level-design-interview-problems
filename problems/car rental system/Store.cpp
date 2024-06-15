#include "models/common.h"
#include "models/Location.h"
#include "VehicleInventoryManagement.cpp"
#include "models/Reservation.h"

class Store {
    int id_;
    Location* storeLocation_;
    VehicleInventoryManagement* vehicleInventory_ = nullptr;
    vector<Reservation*> reservations;

    // update reservation
    void updateReservation(int reservationId, ReservationStatus newStatus)
    {
        for (Reservation *reservation : reservations)
        {
            if (reservation->getReservationId() == reservationId)
            {
                reservation->setReservationStatus(newStatus);
                return;
            }
        }
    }

public:
    Store(int id, Location* loc): id_(id), storeLocation_(loc) {
        vector<Vehicle*> v;

        if (vehicleInventory_ == nullptr) {
            vehicleInventory_ = new VehicleInventoryManagement(v);
        }
    }

    vector<Vehicle*> getVehicles(VehicleType vType) {
        return vehicleInventory_->getVehicles(vType);
    }

    void addVehicles(vector<Vehicle*> vehiclesToAdd) {
        vehicleInventory_->addVehicles(vehiclesToAdd);
    }

    // create reservation
    Reservation* createReservation(User* user, Vehicle* vehicle) {
        Reservation* reservation = new Reservation();
        reservation->createReservation(user, vehicle);
        reservations.push_back(reservation);

        return reservation;
    }

    // complete reservation
    void completeReservation(int reservationId) {
        updateReservation(reservationId, ReservationStatus::COMPLETED);
    }

    // cancel reservation
};