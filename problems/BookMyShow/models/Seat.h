#ifndef SEAT_H
#define SEAT_H
#include "common.h"
#include "User.h"

enum SeatCategory {
    SILVER,
    GOLD,
    PLATINUM
};

class Seat {
    int number_;
    int price_;
    SeatCategory seatCategory_;
    User* bookedFor_ = nullptr;
    bool isBooked_ = false;
public:
    Seat(int number, int price, SeatCategory sc):number_(number),
        price_(price), seatCategory_(sc) {};

    void book(User* user) {
        bookedFor_ = user;
        isBooked_ = true;
    }

    int getNumber() {
        return number_;
    }

    bool isBooked() {
        return isBooked_;
    }
};

#endif //SEAT_H