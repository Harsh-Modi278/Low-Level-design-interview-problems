#ifndef _ENTITY_H
#define _ENTITY_H

#include "common.h"

class Entity {
    EntityType entityType;
    int startIndex;
    int endIndex;
public:
    Entity(EntityType entityType, int s, int e) {
        this->entityType = entityType;
        this->startIndex = s;
        this->endIndex = e;
    }
};

#endif // _ENTITY_H