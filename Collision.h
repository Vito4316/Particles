//
// Created by vito on 04/06/2022.
//

#ifndef PARTICLES_COLLISION_H
#define PARTICLES_COLLISION_H
#include <SFML/Graphics.hpp>
#include "MassPosition.h"

struct CircleCollision {
    float r;
    sf::Vector2f pos;
    CircleCollision(float _r, sf::Vector2f _pos) :
                    r(_r*2), pos(_pos) {}
};

struct SquareCollision {
    sf::Vector2f pos;
    sf::Vector2f rect;
    SquareCollision(sf::Vector2f _rect, sf::Vector2f _pos) :
            rect(_rect), pos(_pos) {}
};

bool areColliding(CircleCollision a, CircleCollision b);
bool areColliding(SquareCollision a, CircleCollision b);
bool areColliding(SquareCollision a, SquareCollision b);

#endif //PARTICLES_COLLISION_H
