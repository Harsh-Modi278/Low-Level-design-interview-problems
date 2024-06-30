#ifndef _AIR_CONDITIONER_
#define _AIR_CONDITIONER_

#include "../common.hpp"

// Receiver
class AirConditoner {
    bool isOn;
    int temperature;
public:
    void turnOnAc() {
        isOn = true;
        cout<<"AC is on\n";
    }

    void turnOffAc() {
        isOn = false;
        cout<<"AC is off\n";
    }

    void setTemperature(int temp) {
        temperature = temp;
        cout<<"Temperature changed to "<<temp<<" \n";
    }

    int getTemperature() {
        return temperature;
    }
};

#endif //_AIR_CONDITIONER_