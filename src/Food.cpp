#include <iostream>
#include <GL/freeglut.h>

#include "Food.hpp"
#include "settings.hpp"

using namespace std;

Food::Food(float x, float y) : Entity(x, y, FOOD_RADIUS) {
    cout << "Food created " << Food::x << " " << Food::y << " " << Food::r << endl;
};
