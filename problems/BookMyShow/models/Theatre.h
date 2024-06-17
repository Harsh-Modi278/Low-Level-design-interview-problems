#ifndef THEATRE_H
#define THEATRE_H

#include "common.h"
#include "Screen.h"
#include "Show.h"

class Theatre {
    int id_;
    string name_;
    City city_;
    set<Screen*> screens;
    set<Show*> shows;
public:
    Theatre(int id, string name, City city): id_(id), name_(name), city_(city) {};
    
    void addShow(Show* show) {
        shows.insert(show);
    }

    void addScreen(Screen* screen) {
        screens.insert(screen);
    }

    bool isPlaying(Movie* movie) {
        for (Show* show: shows) {
            if (show->getMoviePlaying()->getId() == movie->getId()) {
                return true;
            }
        }

        return false;
    }

    set<Show*> getShows(Movie* movie) {
        set<Show*> showsWithMoviePlaying;
        for (Show* show: shows) {
            if (show->getMoviePlaying()->getId() == movie->getId()) {
                showsWithMoviePlaying.insert(show);
            }
        }

        return showsWithMoviePlaying;
    }

    string getName() {
        return name_;
    }
};

#endif //THEATRE_H