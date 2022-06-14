//
// Created by vito on 11/06/2022.
//

#include "CollisionsList.h"

void CollisionsList::insert(uint64_t a, uint64_t b) {
    collisions.insert({a, b});
}

bool CollisionsList::isPresent(uint64_t a, uint64_t b) {
    auto search = collisions.find({a, b});
    if(search != collisions.end())
        return true;
    return false;
}