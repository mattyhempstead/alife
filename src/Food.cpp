#include <iostream>
#include <GL/freeglut.h>

#include "Food.hpp"

using namespace std;

Food::Food() : Entity(0,0,50) {
    cout << "Food created " << Food::x << " " << Food::y << " " << Food::r << endl;
};
