//
// Created by vito on 31/05/2022.
//

#include "Particles.h"
#include "Particle.h"
#include "MassPosition.h"
#include "MyMath.h"
#include "Collision.h"
#include "Defines.h"
#include "timeBenchmark.h"
#include "CollisionsList.h"
#include <cmath>

bool Particles::isParticleOutOfBounds(const Particle<sf::CircleShape>& val) {
    if(std::isfinite(val.getMassPos().getPos().x) && std::isfinite(val.getMassPos().getPos().y))
        return (val.getMassPos().getPos().y - size*2 > window.getSize().y) ||
           (val.getMassPos().getPos().x - size*2 > window.getSize().x) ||
           (val.getMassPos().getPos().y + size*2 < 0) ||
           (val.getMassPos().getPos().x + size*2 < 0);
    return true;
}

void Particles::tick(std::vector<MassPosition> &masses) {
#ifdef BENCHMARK
    timeBenchmark benchmark;
#endif
    for(auto& i : particles)
        masses.push_back(i.getMassPos());

    CollisionsList collisions;
    auto i = particles.begin();
    while(i != particles.end()) {
#ifdef GRAVITY
        sf::Vector2f gravToApply = gravityToApply(masses, i->getMassPosRef());
#else
        sf::Vector2f gravToApply{0,0};
#endif
        resolveCollisionsFor(masses, i->getMassPosRef(), collisions);

        i->tick(gravToApply);

        if(isParticleOutOfBounds(*i))
            particles.erase(i++);
        else
            i++;
    }
}

sf::Vector2f Particles::gravityToApply(std::vector<MassPosition> &masses, MassPosition &i) {
    sf::Vector2f gravToApply{0, 0};
    for(auto& x : masses) {
        auto val = x.getAppliedGravity(i.getPos());
        if(!math::isVectorNan(val))
            gravToApply += val;
    }
    return gravToApply;
}

void Particles::resolveCollisionsFor(std::vector<MassPosition> &masses, MassPosition &i, CollisionsList &list) {
    for(auto& x : masses) {
        if(!(x == i))
            if(areColliding({10, x.getPos()}, {10, i.getPos()})) {
                if(!list.isPresent(x.getID(), i.getID())) {
                    list.insert(x.getID(), i.getID());
                    auto val = x.getAppliedImpulse(i);
                    if (!math::isVectorNan(val)) {
                        x.applyImpulse(-val);
                        i.applyImpulse(val);
                    }
                }
            }
    }
}

void Particles::draw() {
    for(auto& i : particles)
        i.draw(window);
}

void Particles::addParticle() {
    sf::CircleShape circle(size);
    circle.setFillColor(generator.nextColor());

#define range 100
    float randomNumber1 = static_cast<float>(random() % range) - range/2;
    float randomNumber2 = static_cast<float>(random() % range) - range/2;
    sf::Vector2f vel{randomNumber1, randomNumber2};
    math::normalizeVector(vel);
    vel*=maxspeed;

    sf::Vector2f acc{0.0, gravity};

    particles.emplace_back(1, center, vel, acc, circle);
}

void Particles::addParticles(int num) {
    for(int i = 0; i < num; i++)
        addParticle();
}