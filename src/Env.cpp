#include <iostream>
#include <GL/freeglut.h>

#include "Env.hpp"

using namespace std;

Env::Env() {
    cout << "Env created\n";

    Env::rectX = 0.0;
    Env::rectY = 0.0;

    Env::ety = new Food();
}

void Env::draw() {
    ety->draw();
}
