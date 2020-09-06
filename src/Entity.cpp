#include <iostream>
#include <GL/freeglut.h>

#include "Entity.hpp"
#include "draw.hpp"

using namespace std;

Entity::Entity(float x, float y, float r) {
    Entity::x = x;
    Entity::y = y;
    Entity::r = r;
    cout << "Created entity\n";
};

void Entity::draw() {
    draw::circle(x, y, r, draw::green);
}

void Entity::print() {
    cout 
        << "Entity: " 
        << x << " "
        << y << " "
        << r << endl;
}
