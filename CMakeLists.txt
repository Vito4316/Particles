cmake_minimum_required(VERSION 3.21)
project(Particles)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "D:/GameTry/SFML-2.5.1a/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics audio system main REQUIRED)
add_executable(Particles main.cpp Particles.cpp Particles.h Particle.tpp Particle.h RainbowColorGenerator.h ColorGenerator.h MassPosition.cpp MassPosition.h MyMath.h timeBenchmark.h Defines.h MyMath.cpp Collision.cpp Collision.h CollisionsList.cpp CollisionsList.h)
target_link_libraries(Particles sfml-graphics sfml-audio sfml-system sfml-main)