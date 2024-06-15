#ifndef LOCATION_H
#define LOCATION_H

#include "common.h"

class Location {
    string address_;
    string city_;
    string state_;
    string country_;
    int pincode_;
public:
    Location(string address, string city, string state, string country, int pincode): address_(address),
        city_(city),
        state_(state),
        country_(country),
        pincode_(pincode) {};
};

#endif // LOCATION_H