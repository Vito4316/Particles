//
// Created by vito on 04/06/2022.
//

#include "Collision.h"
#include "MyMath.h"
#include "Defines.h"
#include <iostream>

bool areColliding(CircleCollision a, CircleCollision b) {
    sf::Vector2f disVect = a.pos - b.pos;
#ifdef DEBUG
    if(math::pythagoras(disVect) < a.r || math::pythagoras(disVect) < b.r) {
        std::cout<<"Collision:"<<'\n';
        math::printVector(a.pos);
        math::printVector(b.pos);
        std::cout<<math::pythagoras(disVect)<<'\n';
        std::cout<<"------"<<'\n';
    }
#endif

    return math::pythagoras(disVect) < a.r || math::pythagoras(disVect) < b.r;
}

bool areColliding(SquareCollision square, CircleCollision circle) {
    return false;
}

bool areColliding(SquareCollision a, SquareCollision b) {
    return false;
}