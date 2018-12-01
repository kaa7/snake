#include "snake.h"
#include "common.h"
Snake::Snake()
{
    el newEl(800 / 2, 800 / 2);
    v.insert(v.begin(), newEl);
    size = 1;
}

void Snake::reset()
{
    v.clear();
    el newEl(800 / 2, 800 / 2);
    v.insert(v.begin(), newEl);
    size = 1;
}

int Snake::length()
{
    return size;
}

el *Snake::head()
{
    return &v.back();
}

el *Snake::tail()
{
    return &v.front();
}

bool Snake::lookFor(sf::Vector2f p)
{
    for(int i = v.size() - 2; i > 0 ; i--)
        if(v[i].position() == p) return true;
    return false;
}

void Snake::move(direction dir)
{
    sf::Vector2f pos0 = v.back().position();
    sf::Vector2f new_pos = sf::Vector2f(v.back().x() + dir.x * 50,
                                        v.back().y() + dir.y * 50);
    if(o.lookFor(new_pos) || this->lookFor(new_pos)) {
        game_over = true;
        return;
    }
    v.back().move(sf::Vector2f(v.back().x() + dir.x * 50,
                               v.back().y() + dir.y * 50));
    if(size > 1) {

        sf::Vector2f pos1;
        for(int i = v.size() - 2; i > 0 ; i--) {
            pos1 = v[i].position();
            v[i].move(pos0);
            pos0 = pos1;
        }
        if(check) {
            check = false;
            pos1 = v[0].position();
            v[0].move(pos0);
            el newEl(pos1);
            v.insert(v.begin(), newEl);

        } else v[0].move(pos0);
    }
}

void Snake::add()
{
    check = true;
    size++;
}

void Snake::draw()
{
    for(auto i : v) {
        i.draw();
    }
}

