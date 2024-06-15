#include "common.h"
#include "User.h"
#include "Vehicle.h"
#include "Location.h"
#include <ctime>

class Reservation {
    int id;
    User* user;
    Vehicle* vehicle;
    time_t bookingDate;
    time_t dateBookedFrom;
    time_t dateBookedTo;
    Location* pickupLocation;
    Location *dropLocation;
    ReservationStatus reservationStatus;
    ReservationType reservationType;
public:
    int createReservation(User* user, Vehicle* vehicle) {
        //generate new guid
        int reservationId = 1;
        this->id = reservationId;
        this->user = user;
        this->vehicle = vehicle;
        reservationStatus = ReservationStatus::SCHEDULED;
        reservationType = ReservationType::DAILY;

        return reservationId;
    }

    int getReservationId() {
        return id;
    }

    void setReservationStatus(ReservationStatus newStatus) {
        reservationStatus = newStatus;
    }
};