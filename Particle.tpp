//
// Created by vito on 31/05/2022.
//

#include "Particle.h"
#include <iostream>

template <class T>
void Particle<T>::tick(sf::Vector2f gravity) {
    masspos.tick(gravity);
}

template<class T>
void Particle<T>::tick(sf::Vector2f gravity, sf::Vector2f impulse) {
    masspos.tick(gravity, impulse);
}

template <class T>
void Particle<T>::draw(sf::RenderWindow& window) {
    shape.setPosition(masspos.getPos());
    window.draw(shape);
}

template <class T>
Particle<T>::Particle(float mass, sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _acc, T &_shape) :
                    masspos(mass, _pos, _vel, _acc), shape(_shape)
{
    shape.setOrigin({shape.getRadius(), shape.getRadius()});
}

template <class T>
Particle<T>::Particle(MassPosition _mp, T &_shape) :
                    masspos(_mp), shape(_shape)
{
    shape.setOrigin({shape.getRadius(), shape.getRadius()});
}
