#ifndef SCREEN_H
#define SCREEN_H

#include "common.h"
#include "Seat.h"

class Screen {
    int id_;
    set<Seat*> seats_;
public:
    Screen(int id, set<Seat*> seats): id_(id), seats_(seats) {};

    set<Seat*> getSeats() {
        return seats_;
    }

    void bookSeat(User* user, int seatNumber) {
        for (Seat* seat: seats_) {
            if (seat->getNumber() == seatNumber) {
                seat->book(user);
                return;
            }
        }
    }
};

#endif //SCREEN_H