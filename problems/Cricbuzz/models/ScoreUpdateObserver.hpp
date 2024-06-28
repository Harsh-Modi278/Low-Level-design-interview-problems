#include "common.hpp"

class Ball;

class ScoreUpdateObserver {
public:
    void update(Ball* ballDetails);
};