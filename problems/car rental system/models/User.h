#ifndef _USER_H
#define _USER_H

#include "common.h"

class User {
    int id;
    string name;
    int drivingLicense;
public:
    User(int id, string name, int drivingLicense) {
        this->id = id;
        this->name = name;
        this->drivingLicense = drivingLicense;
    }
};

#endif //_USER_H