//
// Created by vito on 31/05/2022.
//

#ifndef PARTICLES_PARTICLE_H
#define PARTICLES_PARTICLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MassPosition.h"

template <class T>
class Particle {
private:
    MassPosition masspos;
    T shape;
public:
    void tick(sf::Vector2f gravity);
    void tick(sf::Vector2f gravity, sf::Vector2f impulse);
    void draw(sf::RenderWindow& window);
    [[nodiscard]] MassPosition getMassPos() const { return masspos;}
    [[nodiscard]] MassPosition& getMassPosRef() { return masspos;}

public:
    Particle(float mass, sf::Vector2f _pos, sf::Vector2f _vel,sf::Vector2f _acc, T &_shape);
    Particle(MassPosition _mp, T &_shape);
};

#include "Particle.tpp"


#endif //PARTICLES_PARTICLE_H
