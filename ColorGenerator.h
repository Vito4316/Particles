//
// Created by vito on 01/06/2022.
//

#ifndef PARTICLES_COLORGENERATOR_H
#define PARTICLES_COLORGENERATOR_H
#include<SFML/Graphics.hpp>

class ColorGenerator {
protected:
    float speed;
public:
    explicit ColorGenerator(float _speed) : speed(_speed) {}
    virtual sf::Color nextColor() = 0;
};


#endif //PARTICLES_COLORGENERATOR_H
