//
// Created by vito on 31/05/2022.
//

#ifndef PARTICLES_RAINBOWCOLORGENERATOR_H
#define PARTICLES_RAINBOWCOLORGENERATOR_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "ColorGenerator.h"

#define PI 3.14159265358979323846

class RainbowColorGenerator : public ColorGenerator {
private:
    sf::Uint8 r = 255, g = 0, b = 0;
    float angle = 0;

private:
    void applyAngle() {
        r = 255 * (cos(angle) + 1) / 2;
        g = 255 * (cos(angle + 2 * PI / 3) + 1) / 2;
        b = 255 * (cos(angle - 2 * PI / 3) + 1) / 2;
    }
public:
    explicit RainbowColorGenerator(float _speed) : ColorGenerator(_speed) {
    }

    sf::Color nextColor() {
        angle+=speed;
        if(angle >= 2 * PI)
            angle = 0;
        applyAngle();
        return {r, g, b};
    }

};


#endif //PARTICLES_RAINBOWCOLORGENERATOR_H
