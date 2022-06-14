//
// Created by vito on 01/06/2022.
//
#include <thread>
#include "MassPosition.h"
#include "MyMath.h"
#include "timeBenchmark.h"
#include "Defines.h"
#define GRAV_CONST 30

uint64_t ID::getNewID()
{
    return ID++;
}

void MassPosition::tick(sf::Vector2f gravity, sf::Vector2f impulse) {
    applyImpulse(impulse);
    tick(gravity);
}

void MassPosition::tick(sf::Vector2f gravity) {
    applyAcc(gravity);
    tick();
}

void MassPosition::tick() {
    applyAcc(acc);
    applyVel(vel);
}

sf::Vector2f MassPosition::getAppliedGravity(const sf::Vector2f &otherPosition) const {
    auto relVector = pos - otherPosition;
    if(relVector.x == 0 && relVector.y == 0)
        return {0, 0};

    float distance = math::pythagorasUnsquared(relVector);
    math::normalizeVector(relVector);

    float gravityAcc = GRAV_CONST * mass / distance;
    relVector *= gravityAcc;

    return relVector;
}

sf::Vector2f MassPosition::getAppliedImpulse(const MassPosition &otherMass) const {
    float e = std::min(this->getE(), otherMass.getE());
    auto norm = math::norm(otherMass.getPos() , this->pos);

    sf::Vector2f relVelocity = otherMass.getVel() - this->vel;

    float impulseMag = -(1 + e) * math::dotProd(relVelocity, norm) /
                       ((1/otherMass.getMass()) * (1/this->mass));

    if(!std::isfinite(impulseMag))
        return {0,0};

    sf::Vector2f impulseVector = norm * impulseMag;
    impulseVector = impulseVector;
    return impulseVector;
}

MassPosition::MassPosition(float _mass, sf::Vector2f _pos) :
                            mass(_mass), pos(_pos)
{
    id = ID::getNewID();
}

MassPosition::MassPosition(float _mass, sf::Vector2f _pos, sf::Vector2f _vel) :
                            mass(_mass), pos(_pos), vel(_vel)
{
    id = ID::getNewID();
}

MassPosition::MassPosition(float _mass, sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _acc) :
                            mass(_mass), pos(_pos), vel(_vel), acc(_acc)
{
    id = ID::getNewID();
}

void MassPosition::applyImpulse(sf::Vector2f impulse) {
#ifdef DEBUG
    float x;
    if(impulse != sf::Vector2f{0,0})
        x = math::pythagoras(vel);
#endif
    if(modifiable)
        if(!math::isVectorNan(impulse)) {
            vel = vel + impulse / mass;
        }
#ifdef DEBUG
    if(impulse != sf::Vector2f{0,0})
        std::cout<<"relvel:" <<x<<"->"<< math::pythagoras(vel) << '\n';
#endif
}