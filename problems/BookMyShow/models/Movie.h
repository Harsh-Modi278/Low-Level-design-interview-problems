#ifndef MOVIE_H
#define MOVIE_H

#include "common.h"

class Movie {
    int id_;
    string name_;
    int durationMins_;
public:
    Movie(int id, string name, int durationMins): id_(id), name_(name),durationMins_(durationMins) {};

    string getName() {
        return name_;
    }

    int getId() {
        return id_;
    }
};

#endif //MOVIE_H