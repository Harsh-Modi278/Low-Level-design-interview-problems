#include "models/Dice.h"

int Dice::roll() {
    int value = 1 + rand()%6;

    return value;
}