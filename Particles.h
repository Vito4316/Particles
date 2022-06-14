//
// Created by vito on 31/05/2022.
//

#ifndef PARTICLES_PARTICLES_H
#define PARTICLES_PARTICLES_H
#include <list>
#include <random>
#include "RainbowColorGenerator.h"
#include "Particle.h"
#include "MassPosition.h"
#include "CollisionsList.h"

class Particles {
private:
    std::list<Particle<sf::CircleShape>> particles;
    float gravity;
    float size;
    float maxspeed;
    sf::Vector2f center;
    sf::RenderWindow& window;
    RainbowColorGenerator generator;
    std::random_device random;

public:
    void addParticle();
    void addParticles(int num);
    void tick(std::vector<MassPosition> &masses);
    void draw();
    bool isParticleOutOfBounds(const Particle<sf::CircleShape>& val);
    static sf::Vector2f gravityToApply(std::vector<MassPosition> &masses, MassPosition &i);
    static void resolveCollisionsFor(std::vector<MassPosition> &masses, MassPosition &i, CollisionsList& list);
    [[nodiscard]] int getNumParticles() const {return particles.size();}
    [[nodiscard]] float getSize() const {return size;}
    void setCenter(sf::Vector2f pos) {center = pos;}

    Particles(float _maxspeed, float _gravity, float _size, sf::RenderWindow& _window, sf::Vector2f& _center) :
            maxspeed(_maxspeed), gravity(_gravity) , size(_size), window(_window), center(_center), generator(0.1) {
    }
};


#endif //PARTICLES_PARTICLES_H
