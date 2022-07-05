//
// Created by vito on 11/06/2022.
//

#ifndef PARTICLES_COLLISIONSLIST_H
#define PARTICLES_COLLISIONSLIST_H
#include <unordered_set>
#include <cstdint>

struct CollisionID {
public:
    uint64_t idA;
    uint64_t idB;

public:
    bool operator==(CollisionID other) const {
        if(idA == other.idA && idB == other.idB) return true;
        if(idA == other.idB && idB == other.idA) return true;
        return false;
    }

public:
    CollisionID(uint64_t a, uint64_t b) : idA(a), idB(b) {}

};

namespace std {
    template <>
    struct hash<CollisionID>
    {
        std::size_t operator()(const CollisionID& k) const
        {
            using std::hash;
            return hash<uint64_t>()(k.idA) + hash<uint64_t>()(k.idB);
        }
    };
}

class CollisionsList{
private:
    std::unordered_set<CollisionID> collisions;

public:
    void insert(uint64_t a, uint64_t b);
    bool isPresent(uint64_t a, uint64_t b);
};


#endif //PARTICLES_COLLISIONSLIST_H
