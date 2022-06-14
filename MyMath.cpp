//
// Created by vito on 04/06/2022.
//
#include "MyMath.h"
#include <cmath>
#include <iostream>

float math::pythagorasUnsquared(const sf::Vector2<float> &components) {
    return components.x * components.x +
           components.y * components.y;
}

float math::pythagoras(const sf::Vector2f &components) {
    return sqrt(pythagorasUnsquared(components));
}

void math::normalizeVector(sf::Vector2<float> &vector) {
    float norm = pythagoras(vector);

    vector.x /= norm;
    vector.y /= norm;
}

constexpr double math::sqrtNewtonRaphson(double x, double curr, double prev)
{
    return curr == prev
           ? curr
           : sqrtNewtonRaphson(x, 0.5 * (curr + x / curr), curr);
}

constexpr double math::my_sqrt(double x)
{
    return x >= 0 && x < std::numeric_limits<double>::infinity()
           ? sqrtNewtonRaphson(x, x, 0)
           : std::numeric_limits<double>::quiet_NaN();
}

float math::dotProd(sf::Vector2f a, sf::Vector2f b) {
    return a.x * b.x + a.y * b.y;
}

bool math::isVectorNan(sf::Vector2f x) {
#ifdef DEBUG
    auto y = !(std::isfinite(x.x) && std::isfinite(x.y));
#endif
    return !(std::isfinite(x.x) && std::isfinite(x.y));
}

sf::Vector2f math::norm(sf::Vector2f pos1, sf::Vector2f pos2) {
    auto norm = pos1 - pos2;
    if(math::isVectorNan(norm)) {
        return {0,0};
    }
    math::normalizeVector(norm);
    return norm;
}

void math::printVector(sf::Vector2f v) {
    std::cout<<v.x<<"-"<<v.y<<'\n';
}


