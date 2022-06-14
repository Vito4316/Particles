#include <iostream>
#include <SFML/Graphics.hpp>
#include "Particles.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Particle");

    sf::Vector2f center(250, 250);
    Particles particles(0.1, 0, 10, window, center);

#ifdef MORBING_TIME
    sf::Texture texture;
    if (!texture.loadFromFile("morb_sun.png"))
        return -1;

    sf::CircleShape circle(10);
    Particle<sf::CircleShape> morbius({10, {100,100}, {0,0}, {0,0}},
                                      circle);
    morbius.getMassPosRef().toggleModifiable();
#endif

    window.setFramerateLimit(60);

    int maxpart = 0;


    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized) {
                window.setView(
                        sf::View(
                                sf::FloatRect(
                                        0, 0,
                                        event.size.width, event.size.height)
                                )
                              );
            }
            else if(event.type == sf::Event::MouseButtonPressed) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    auto pos = sf::Mouse::getPosition(window);
                    particles.setCenter(window.mapPixelToCoords(pos));
                    particles.addParticles(1);
                }
            }

        }

        window.clear(sf::Color(255, 228, 192));

        std::vector<MassPosition> masspos;
#ifdef MORBING_TIME
        masspos.emplace_back(morbius.getMassPos());
        morbius.draw(window);
#endif
        particles.draw();
        particles.tick(masspos);

        window.display();

        if(maxpart < particles.getNumParticles())
            maxpart = particles.getNumParticles();
    }

    std::cout<<maxpart;

    return 0;
}