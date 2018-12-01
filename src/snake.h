#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "el.h"
#include "obstacles.h"
#include "common.h"
using namespace std;
struct el;
struct direction;

struct Snake {
private:
    vector<el> v;
    int size;
    bool check = false;
public:
    Snake();
    int length();
    el *head();
    el *tail();
    bool lookFor(sf::Vector2f p);
    void move(direction dir);
    void add();
    void draw();
    void reset();
};

#endif // SNAKE_H
