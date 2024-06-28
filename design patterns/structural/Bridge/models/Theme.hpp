#ifndef _THEME_H_
#define _THEME_H_

#include "common.hpp"

class Theme {
protected:
    string color_;
public:
    string getColor() {
        return color_;
    };
};

#endif //_THEME_H_