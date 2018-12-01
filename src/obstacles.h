#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <vector>
#include "obstacle.h"
using namespace std;
struct obstacles {
private:
    vector<obstacle> v;
public:
    void add(obstacle obj);
    void draw();
    void generate();
    obstacles();
    bool lookFor(sf::Vector2f p);
};
#endif // OBSTACLES_H
