//
// Created by vito on 01/06/2022.
//

#ifndef PARTICLES_MASSPOSITION_H
#define PARTICLES_MASSPOSITION_H
#include <SFML/graphics.hpp>
#include <cmath>

namespace ID {
    static uint64_t ID = 0;

    uint64_t getNewID();
}

class MassPosition {
private:
    float mass;
    sf::Vector2f vel;
    sf::Vector2f acc;
    sf::Vector2f pos;
    bool modifiable = true;
    uint64_t id;

public:
    void tick(sf::Vector2f gravity, sf::Vector2f impulse);
    void tick(sf::Vector2f gravity);
    void tick();
    void setPos(sf::Vector2f newPos) {if(modifiable) pos = newPos;}
    void applyVel(sf::Vector2f velocity) {if(modifiable)  pos+= velocity;}
    void applyAcc(sf::Vector2f acceleration) {if(modifiable) vel+= acceleration;}
    void applyImpulse(sf::Vector2f impulse);
    void toggleModifiable() {modifiable = !modifiable;}

    [[nodiscard]] sf::Vector2f getPos() const {return pos;}
    [[nodiscard]] float getE() const {return 1;}
    [[nodiscard]] float getMass() const {return mass;}
    [[nodiscard]] sf::Vector2f getVel() const {return vel;}
    [[nodiscard]] uint64_t getID() const {return id;}

    [[nodiscard]] sf::Vector2f getAppliedGravity(const sf::Vector2f &otherPosition) const;
    [[nodiscard]] sf::Vector2f getAppliedImpulse(const MassPosition &otherMass) const;

    bool operator==(MassPosition& other) const {
        return id == other.getID();
    }
public:
    MassPosition(float _mass, sf::Vector2f _pos);
    MassPosition(float _mass, sf::Vector2f _pos, sf::Vector2f _vel);
    MassPosition(float _mass, sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _acc);
};


#endif //PARTICLES_MASSPOSITION_H
