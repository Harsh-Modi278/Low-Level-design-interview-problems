#ifndef SHOW_H
#define SHOW_H

#include "Movie.h"
#include "Screen.h"

// Theatre has shows (1:many)
// Theatre has screens (1:many)
// Show has a Movie (1:1)
// Show has a Screen (1:1)
class Show {
    int id_;
    Movie* movie_;
    Screen* screen_;
    int startTime_;
    int endTime_;
public:
    Show(int id, Movie* movie, Screen* screen, int startTime):id_(id), movie_(movie), screen_(screen), startTime_(startTime) {};

    Movie* getMoviePlaying() {
        return movie_;
    }

    int getStartTiming() {
        return startTime_;
    }

    set<int> getEmptySeatIds() {
        set<int> emptySeatIds;
        set<Seat*> seats = screen_->getSeats();
        for (Seat* seat: seats) {
            if (!seat->isBooked()) {
                emptySeatIds.insert(seat->getNumber());
            }
        }

        return emptySeatIds;
    }

    Screen* getScreen() {
        return screen_;
    }
};

#endif //SHOW_H