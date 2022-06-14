//
// Created by vito on 01/06/2022.
//

#ifndef PARTICLES_MYMATH_H
#define PARTICLES_MYMATH_H
#include <SFML/Graphics.hpp>

namespace math {
    float pythagorasUnsquared(const sf::Vector2<float> &components);
    float pythagoras(const sf::Vector2f &components);
    void normalizeVector(sf::Vector2<float> &vector);
    float dotProd(sf::Vector2f a, sf::Vector2f b);
    bool isVectorNan(sf::Vector2f x);
    sf::Vector2f norm(sf::Vector2f pos1, sf::Vector2f pos2);
    constexpr double sqrtNewtonRaphson(double x, double curr, double prev);
    constexpr double my_sqrt(double x);

    void printVector(sf::Vector2f v);
}

#endif //PARTICLES_MYMATH_H

